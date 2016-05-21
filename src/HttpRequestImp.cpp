//
//  HttpRequestImp.cpp
//  gearsbox
//
//  Created by dyno on 5/17/16.
//
//

#include "HttpRequestImp.hpp"
#include "ILog.h"
#include "callback_http_gen.hpp"
#include <set>

using namespace gearsbox;

static std::set<std::shared_ptr<HttpRequestGen>> s_requests_set;

std::shared_ptr<HttpRequestGen> HttpRequestGen::create(){
    std::shared_ptr<HttpRequestGen> newone = std::make_shared<HttpRequestImp>();
    s_requests_set.insert(newone);
    return newone;
}

void remove_request(std::shared_ptr<HttpRequestGen> target){
    s_requests_set.erase(target);
    //G_LOG_FC(LOG_INFO,"remove done %x", target.get());
}

HttpRequestImp::HttpRequestImp():m_callback(nullptr),m_stay(nullptr){
    //G_LOG_FC(LOG_INFO, "new HttpRequestImp %lx", this);
}
HttpRequestImp::~HttpRequestImp(){
    m_callback = nullptr;
    //G_LOG_FC(LOG_INFO, "~HttpRequestImp %lx", this);
}

int64_t HttpRequestImp::get(const std::string &url, const std::shared_ptr<CallbackHttpGen> &callback){
    m_stay = shared_from_this();
    if (nullptr ==callback){
        G_LOG_FC(LOG_ERROR,"gen http request callback null %lx", callback.get());
        remove_request(m_stay);
        return 0;
    }
    
    m_callback = callback;
    IHttpRequest* http_request = IHttpRequest::create();
    http_request->setRequest(url,
                             std::bind(&HttpRequestImp::HttpResult, this,std::placeholders::_1));
    http_request->start();
    m_stay = shared_from_this();
    return (int64_t)this;
}

void HttpRequestImp::HttpResult(IHttpRequest *request){
    if (!request){
        G_LOG_FC(LOG_ERROR,"result null");
        return;
    }
    const HTTP_RESULT& result = request->getResult();
    //G_LOG_FC(LOG_INFO, "%s, data:%s", result.result?"sucess":"fail", result.content.c_str());
    
    if (m_callback)
        m_callback->callback((int64_t)this, result.result, result.content);

    delete request;
    remove_request(m_stay);
    m_stay = nullptr;
}
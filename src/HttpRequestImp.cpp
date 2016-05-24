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

std::shared_ptr<HttpRequestGen> HttpRequestGen::create(){
    std::shared_ptr<HttpRequestGen> newone = std::make_shared<HttpRequestImp>();
    return newone;
}

HttpRequestImp::HttpRequestImp():m_callback(nullptr){
    //G_LOG_FC(LOG_INFO, "new HttpRequestImp %lx", this);
}
HttpRequestImp::~HttpRequestImp(){
    m_callback = nullptr;
    m_request_ptr = nullptr;
    //G_LOG_FC(LOG_INFO, "~HttpRequestImp %lx", this);
}

int64_t HttpRequestImp::get(const std::string &url, const std::shared_ptr<CallbackHttpGen> &callback){
    if (nullptr ==callback){
        G_LOG_FC(LOG_ERROR,"gen http request callback null %lx", callback.get());
        return 0;
    }
    
    m_callback = callback;
    m_request_ptr = IHttpRequest::create();
    m_request_ptr->setRequest(url,
                             std::bind(&HttpRequestImp::HttpResult, this,std::placeholders::_1));
    m_request_ptr->start();
    return (int64_t)this;
}

void HttpRequestImp::HttpResult(std::shared_ptr<IHttpRequest> request){
    if (!request){
        G_LOG_FC(LOG_ERROR,"result null");
        return;
    }
    const HTTP_RESULT& result = request->getResult();
    //G_LOG_FC(LOG_INFO, "%s, data:%s", result.result?"sucess":"fail", result.content.c_str());
    
    if (m_callback)
        m_callback->callback((int64_t)this, result.result, result.content);
}
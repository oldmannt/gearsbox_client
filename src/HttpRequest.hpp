//
//  HttpRequest.hpp
//  nb_uv_run
//
//  Created by dyno on 5/3/16.
//  Copyright © 2016 dyno. All rights reserved.
//

#ifndef HttpRequest_hpp
#define HttpRequest_hpp

#include <map>
#include "uv.h"
#include "curl/curl.h"
#include "IHttpRequest.h"

namespace gearsbox {

class HttpRequest:public IHttpRequest, public std::enable_shared_from_this<HttpRequest>{
public:
    HttpRequest();
    virtual ~HttpRequest();
    
    virtual int setRequestUrl(const std::string& url);
    virtual int setResultCallback(HttpResultCallback rc);
    virtual int setRetryTimes(int retry_times);
    virtual int setRequestTimeout(long time_out);
    virtual int setRequest(const std::string& url, HttpResultCallback cb, unsigned long timeout = 60000,
                   int retry_times = 0);
    
    virtual int setPostData(const std::string& message);
    virtual int setPostData(const void* data, unsigned long size);
    virtual int setRequestProxy(const std::string& proxy, int proxy_port);
    
    virtual int start();
    virtual const HTTP_RESULT& getResult() const{return m_result;}
    
    void handleResult(CURLMsg* message);
    size_t writeHeader(char* data, unsigned long size);
    size_t writeContent(char* data, unsigned long size);
    void cleanUP();
   
private:
    int Retry();
    unsigned long m_timeout;
    int m_retry_times;
    HttpResultCallback m_callback;
    std::string m_proxy;
    int m_port;
    HTTP_RESULT m_result;
    char*  m_post_data;
    CURL* m_handle;
};
    
typedef std::map<IHttpRequest*, std::shared_ptr<IHttpRequest>> MAP_PTR_REQUEST;
class HttpRequestMgr{
public:
    HttpRequestMgr():m_init(false),m_curlm_handle(0){};
    
    static HttpRequestMgr& instance(){
        static HttpRequestMgr s_instance;
        return s_instance;
    }
    
    bool init();
    uv_timer_t* getUVTimer(){return &m_httpuvtimeout;}
    CURLM* getCurlm(){ return m_curlm_handle;}
    
    bool addHttpRequest(std::shared_ptr<IHttpRequest> request_ptr);
    bool removeHttpRequest(IHttpRequest* request_raw);
    bool removeHttpRequest(std::shared_ptr<IHttpRequest>);
    
private:
    bool m_init;
    CURLM * m_curlm_handle;
    uv_timer_t m_httpuvtimeout;
    
    MAP_PTR_REQUEST m_living_request;
};

}
#endif /* HttpRequest_hpp */

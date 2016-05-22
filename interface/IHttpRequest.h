//
//  IHttpRequest.h
//  gearsbox
//
//  Created by dyno on 5/16/16.
//
//

#ifndef IHttpRequest_h
#define IHttpRequest_h

#include <string>
#include <functional>
#include <memory>

namespace gearsbox {

typedef enum {
    REQUEST_OK =0,
}RequestResult;

class IHttpRequest;
    typedef std::function<void(std::shared_ptr<IHttpRequest>)> HttpResultCallback;

struct HTTP_RESULT {
    HTTP_RESULT():result(false),response_code(0){}
    bool result;
    long response_code;
    std::string url;
    std::string header;
    std::string content;
    std::string err;
};


class IHttpRequest {
public:
    static std::shared_ptr<IHttpRequest> create();
    virtual~ IHttpRequest(){};
    virtual int setRequestUrl(const std::string& url) = 0;
    virtual int setResultCallback(HttpResultCallback rc) = 0;
    virtual int setRetryTimes(int retry_times) = 0;
    virtual int setRequestTimeout(long time_out) = 0;
    virtual int setRequest(const std::string& url, HttpResultCallback cb, unsigned long timeout = 60000,
                   int retry_times = 0) = 0;
    virtual int setPostData(const std::string& message) = 0;
    virtual int setPostData(const void* data, unsigned long size) = 0;
    virtual int setRequestProxy(const std::string& proxy, int proxy_port) = 0;
    
    virtual int start() = 0;
    virtual const HTTP_RESULT& getResult() const = 0;
};

}
#endif /* IHttpRequest_h */

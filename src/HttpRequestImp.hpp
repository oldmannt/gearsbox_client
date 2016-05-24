//
//  HttpRequestImp.hpp
//  gearsbox
//
//  Created by dyno on 5/17/16.
//
//

#ifndef HttpRequestImp_hpp
#define HttpRequestImp_hpp

#include "IHttpRequest.h"
#include "http_request_gen.hpp"

namespace gearsbox {

class HttpRequestImp: public HttpRequestGen{
public:
    HttpRequestImp();
    virtual ~HttpRequestImp();
    virtual int64_t get(const std::string & url, const std::shared_ptr<CallbackHttpGen> & callback);
    
    void HttpResult(std::shared_ptr<IHttpRequest> result);
private:
    std::shared_ptr<CallbackHttpGen> m_callback;
    std::shared_ptr<IHttpRequest> m_request_ptr;
};
    
}
#endif /* HttpRequestImp_hpp */

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from gearsbox.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace gearsbox {

class CallbackHttpGen;

class HttpRequestGen {
public:
    virtual ~HttpRequestGen() {}

    static std::shared_ptr<HttpRequestGen> create();

    virtual int64_t get(const std::string & url, const std::shared_ptr<CallbackHttpGen> & callback) = 0;
};

}  // namespace gearsbox
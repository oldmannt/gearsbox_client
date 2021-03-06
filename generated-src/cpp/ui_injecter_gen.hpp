// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#pragma once

#include <memory>
#include <string>

namespace gearsbox {

class ViewGen;

class UiInjecterGen {
public:
    virtual ~UiInjecterGen() {}

    static std::shared_ptr<UiInjecterGen> instance();

    virtual void inject(const std::string & id, const std::shared_ptr<ViewGen> & view) = 0;

    virtual std::shared_ptr<ViewGen> getView(const std::string & id) = 0;

    virtual void removeView(const std::string & id) = 0;
};

}  // namespace gearsbox

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#pragma once

#include <string>

namespace gearsbox {

struct ViewFrame;

class ViewGen {
public:
    virtual ~ViewGen() {}

    virtual std::string getId() = 0;

    virtual void setFrame(const ViewFrame & frame) = 0;

    virtual ViewFrame getFrame() = 0;

    virtual void setBackgroundColor(float a, float r, float g, float b) = 0;

    virtual void setVisiable(bool v) = 0;
};

}  // namespace gearsbox

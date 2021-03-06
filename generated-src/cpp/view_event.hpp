// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#pragma once

#include <functional>

namespace gearsbox {

enum class ViewEvent : int {
    EVENT_NONE,
    EVENT_TAP,
    EVENT_TEXT_CHANGED,
    EVENT_BTN,
};

}  // namespace gearsbox

namespace std {

template <>
struct hash<::gearsbox::ViewEvent> {
    size_t operator()(::gearsbox::ViewEvent type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std

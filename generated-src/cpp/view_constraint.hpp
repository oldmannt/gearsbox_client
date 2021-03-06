// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#pragma once

#include "constraint_type.hpp"
#include <string>
#include <utility>

namespace gearsbox {

struct ViewConstraint final {

    static std::string const PARENT;
    ConstraintType type;
    ConstraintType type_to;
    std::string view_from;
    std::string view_to;
    float multiplier;
    float offset;

    ViewConstraint(ConstraintType type_,
                   ConstraintType type_to_,
                   std::string view_from_,
                   std::string view_to_,
                   float multiplier_,
                   float offset_)
    : type(std::move(type_))
    , type_to(std::move(type_to_))
    , view_from(std::move(view_from_))
    , view_to(std::move(view_to_))
    , multiplier(std::move(multiplier_))
    , offset(std::move(offset_))
    {}
};

}  // namespace gearsbox

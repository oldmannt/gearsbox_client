//
//  IUIConfReader.h
//  gearsbox
//
//  Created by dyno on 5/27/16.
//
//

#ifndef IUIConfReader_h
#define IUIConfReader_h

#include <string>
#include <list>
#include <memory>

#include "constraint_type.hpp"
#include "view_constraint.hpp"
#include "view_type.hpp"
#include "json/json.h"

namespace gearsbox{
    
    typedef std::list<std::shared_ptr<ViewConstraint>> LST_CONSTRAINT;
    struct ViewConf{
        typedef std::map<std::string, std::shared_ptr<ViewConf>> MapViewConf;
        std::string name;
        ViewType type;
        LST_CONSTRAINT constrains;
        MapViewConf sub_views;

        ViewConf(const std::string& name_,ViewType type_)
        : name(name_), type(type_) {}
        ViewConf()
        :type(ViewType::VIEW_BASE) {}
    };

    class IConstraintReader{
    public:
        static std::shared_ptr<IConstraintReader> create();
        virtual ~IConstraintReader();
        virtual bool read(const Json::Value& json);
        virtual std::shared_ptr<ViewConstraint> getConstraint();
    };
    
    class IViewReader{
    public:
        static std::shared_ptr<IViewReader> create();
        virtual ~IViewReader();
        virtual bool read(const Json::Value& json);
        virtual std::shared_ptr<ViewConf> getViewData();
    };
}


#endif /* IUIConfReader_h */

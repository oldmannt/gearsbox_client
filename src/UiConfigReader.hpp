//
//  UiConfigReader.hpp
//  gearsbox
//
//  Created by dyno on 5/27/16.
//
//

#ifndef UiConfigReader_hpp
#define UiConfigReader_hpp

#include "IUIConfReader.h"


namespace gearsbox {
    
    
    class ConstraintReader:public IConstraintReader{
    public:
        ConstraintReader():m_constraint(nullptr){};
        virtual ~ConstraintReader();
        
        virtual bool read(const Json::Value& json);
        virtual std::shared_ptr<ViewConstraint> getConstraint();
    private:
        std::string m_conf;
        std::shared_ptr<ViewConstraint> m_constraint;
        
        ConstraintType readConstrainType(const std::string& conf);
    };
    
    class ViewReader:public IViewReader{
    public:
        ViewReader():m_viewData(nullptr){};
        virtual ~ViewReader();
        
        virtual bool read(const Json::Value& json);
        virtual std::shared_ptr<ViewConf> getViewData();
        
    private:
        std::shared_ptr<ViewConf> m_viewData;
        
        bool readViewData(const Json::Value& json, std::shared_ptr<ViewConf> viewConf);
        ViewType readViewType(const std::string& conf);
    };
}
#endif /* UiConfigReader_hpp */

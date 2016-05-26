//
//  ui_injecter.hpp
//  gearsbox
//
//  Created by dyno on 5/25/16.
//
//

#ifndef ui_injecter_hpp
#define ui_injecter_hpp

#include "ui_injecter_gen.hpp"
#include "view_group_gen.hpp"

#include <map>
namespace gearsbox {

class UiInjecterImpl:public UiInjecterGen{
public:
    UiInjecterImpl();
    virtual ~UiInjecterImpl();
    
    virtual void inject(const std::string & id, const std::shared_ptr<ViewGroupGen> & view_group);
    virtual void getViewGroup(const std::string & id);
    
private:
    typedef std::map<std::string, std::shared_ptr<ViewGroupGen>> MapViewGroup;
    
};
    
}

#endif /* ui_injecter_hpp */

//
//  ui_injecter.cpp
//  gearsbox
//
//  Created by dyno on 5/25/16.
//
//

#include "ui_injecter_imp.hpp"
#include "ILog.h"

using namespace gearsbox;

std::shared_ptr<UiInjecterGen> UiInjecterGen::instance(){
    static std::shared_ptr<UiInjecterImp> s_ptr = std::make_shared<UiInjecterImp>();
    return s_ptr;
}

UiInjecterImp::UiInjecterImp(){
    
}

UiInjecterImp::~UiInjecterImp(){
    m_mapViewGroup.clear();
}

void UiInjecterImp::inject(const std::string &id, const std::shared_ptr<ViewGroupGen> &view_group){
    m_mapViewGroup[id] = view_group;
}

void UiInjecterImp::removeViewGroup(const std::string &id){
    MapViewGroup::iterator it(m_mapViewGroup.find(id));
    if (it==m_mapViewGroup.end()){
        G_LOG_FC(LOG_ERROR, "id dont' exist, nothing to remove");
    }
    m_mapViewGroup.erase(it);
}

std::shared_ptr<ViewGroupGen> UiInjecterImp::getViewGroup(const std::string &id){
    MapViewGroup::iterator it(m_mapViewGroup.find(id));
    if (it==m_mapViewGroup.end()){
        G_LOG_FC(LOG_ERROR, "id dont' exist, nothing finded");
    }
    return it->second;

}
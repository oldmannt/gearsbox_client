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
    m_mapView.clear();
}

void UiInjecterImp::inject(const std::string &id, const std::shared_ptr<ViewGen> &view){
    m_mapView[id] = view;
}

void UiInjecterImp::removeView(const std::string &id){
    MapView::iterator it(m_mapView.find(id));
    if (it==m_mapView.end()){
        G_LOG_FC(LOG_ERROR, "id dont' exist, nothing to remove");
    }
    m_mapView.erase(it);
}

std::shared_ptr<ViewGen> UiInjecterImp::getView(const std::string &id){
    MapView::iterator it(m_mapView.find(id));
    if (it==m_mapView.end()){
        G_LOG_FC(LOG_ERROR, "id dont' exist, nothing finded");
    }
    return it->second;

}
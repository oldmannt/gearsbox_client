//
//  UiConfigReader.cpp
//  gearsbox
//
//  Created by dyno on 5/27/16.
//
//

#include "UiConfigReader.hpp"
#include "ILog.h"

using namespace gearsbox;

std::shared_ptr<IConstraintReader> IConstraintReader::create(){
    return std::make_shared<ConstraintReader>();
}

std::shared_ptr<IViewReader> IViewReader::create(){
    return std::make_shared<ViewReader>();
}

ConstraintReader::~ConstraintReader(){
    m_constraint = nullptr;
}

ViewReader::~ViewReader(){
    m_viewData = nullptr;
}

bool ConstraintReader::read(const Json::Value &json){
    m_constraint = std::make_shared<ViewConstraint>(
                                                    readConstrainType(json["type_from"].asString()),
                                                    readConstrainType(json["type_to"].asString()),
                                                    json["frome"].asString(),
                                                    json["to"].asString(),
                                                    json["multiplier"].asFloat(),
                                                    json["offset"].asFloat() );
    if (m_constraint->view_from.empty()||
        m_constraint->type == ConstraintType::NONE){
        G_LOG_FC(LOG_ERROR, "read constaint failed null");
        return false;
    }

    return true;
}

ConstraintType ConstraintReader::readConstrainType(const std::string& conf){
    if ("leading"==conf)
        return ConstraintType::LEADING;
    else if ("trailing"==conf)
        return ConstraintType::TRAILING;
    else if ("top"==conf)
        return ConstraintType::TOP;
    else if ("bottom"==conf)
        return ConstraintType::BOTTOM;
    else if ("width"==conf)
        return ConstraintType::WIDTH;
    else if ("height"==conf)
        return ConstraintType::HEIGHT;
    else if ("centerx"==conf)
        return ConstraintType::CENTERX;
    else if ("centery"==conf)
        return ConstraintType::CENTERY;
    else
        return ConstraintType::NONE;
}

bool ViewReader::read(const Json::Value &json){
    m_viewData = std::make_shared<ViewConf>();
    return this->readViewData(json, m_viewData);
}

std::shared_ptr<ViewConf> ViewReader::getViewData(){
    return m_viewData;
}

bool ViewReader::readViewData(const Json::Value& json, std::shared_ptr<ViewConf> viewConf){
    if (json.type() == Json::ValueType::nullValue){
        G_LOG_FC(LOG_ERROR, "read view conf json null");
        return false;
    }
    
    viewConf->name = json["name"].asString();
    viewConf->type = this->readViewType(json["type"].asString());
    
    Json::Value constaintsConf = json["constraints"];
    if (constaintsConf.type() == Json::ValueType::arrayValue){
        for (int i=0; i<constaintsConf.size(); ++i) {
            std::shared_ptr<IConstraintReader> constraintReader = IConstraintReader::create();
            if (!constraintReader->read(constaintsConf[i])){
                continue;
            }
            viewConf->constrains.push_back(constraintReader->getConstraint());
        }
    }
    
    Json::Value subViewsJson = json["views"];
    if (subViewsJson.type() == Json::ValueType::arrayValue){
        for (int i=0; i<subViewsJson.size(); ++i) {
            if (subViewsJson[i].type() == Json::ValueType::nullValue){
                G_LOG_FC(LOG_ERROR, "read subview failed json value null");
                continue;
            }
            std::shared_ptr<ViewConf> subViewConf = std::make_shared<ViewConf>();
            if (!this->readViewData(subViewsJson[i],subViewConf)){
                G_LOG_FC(LOG_ERROR, "read subview failed");
                continue;
            }
            viewConf->sub_views[viewConf->name] = subViewConf;
        }
    }
    return true;
}

ViewType ViewReader::readViewType(const std::string& conf){
    if ("view_label"==conf)
        return ViewType::VIEW_LABEL;
    else if("view_input"==conf)
        return ViewType::VIEW_INPUT;
    else if("view_btn"==conf)
        return ViewType::VIEW_BTN;
    else
        return ViewType::VIEW_BASE;
}

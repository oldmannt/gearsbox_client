//
//  gearbox_log_imp.cpp
//  gearsbox
//
//  Created by dyno on 5/17/16.
//
//

#include "log_imp.hpp"
#include "ILog.h"

using namespace gearsbox;

std::shared_ptr<LogGen> LogGen::instance(){
    static std::shared_ptr<LogImp> s_gearbox_log = std::make_shared<LogImp>();
    return s_gearbox_log;
}

bool LogImp::init_(int32_t output, const std::string & param){
    return LOG_OK == g_loginit(output, param.c_str());
}

void LogImp::log(int32_t output, int32_t lev, const std::string &msg){
    g_logouts(output, lev, msg.c_str());
}


//
//  gearbox_log_imp.hpp
//  gearsbox
//
//  Created by dyno on 5/17/16.
//
//

#ifndef gearbox_log_imp_hpp
#define gearbox_log_imp_hpp

#include "log_gen.hpp"

namespace gearsbox {
    class LogImp: public LogGen{
        
        virtual bool init_(int32_t output, const std::string & param);
        virtual void log(int32_t output, int32_t lev, const std::string & msg);
    };
}
#endif /* gearbox_log_imp_hpp */

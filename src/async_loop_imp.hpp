//
//  async_loop_imp.hpp
//  gearsbox
//
//  Created by dyno on 5/17/16.
//
//

#ifndef async_loop_imp_hpp
#define async_loop_imp_hpp

#include "async_loop_gen.hpp"

namespace gearsbox {
    
    class AsyncLoopImp:public AsyncLoopGen{
        virtual void process(int64_t elapse);
    };
}

#endif /* async_loop_imp_hpp */

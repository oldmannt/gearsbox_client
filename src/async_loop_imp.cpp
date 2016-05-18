//
//  async_loop_imp.cpp
//  gearsbox
//
//  Created by dyno on 5/17/16.
//
//

#include "async_loop_imp.hpp"
#include "uv.h"

using namespace gearsbox;

std::shared_ptr<AsyncLoopGen> AsyncLoopGen::instance(){
    static std::shared_ptr<AsyncLoopGen> s_async_loop = std::make_shared<AsyncLoopImp>();
    return s_async_loop;
}

void AsyncLoopImp::process(int64_t elapse){
    uv_run(uv_default_loop(), UV_RUN_NOWAIT);
}


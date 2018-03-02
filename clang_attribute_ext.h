//
//  clang_attribute_ext.h
//  MEngine
//
//  Created by liuxiang on 2018/2/24.
//  Copyright © 2018年 6hao. All rights reserved.
//
#pragma once

#import "clang_attributes_easy_define.h"

#ifndef clang_attribute_ext_h
#define clang_attribute_ext_h


#if !defined(SCOPE_FREE)
#define SCOPE_FREE ATTR_CLEANUP(free)
#endif


__BEGIN_DECLS__
static void AttributeBlockCleanup(__strong void(^*block)(void))
{
    (*block)();
}
__END_DECLS__
#if !defined(ON_EXIT)
#define ON_EXIT __strong void (^exitBlock)(void) ATTR_CLEANUP(AttributeBlockCleanup) = ^
#endif


#endif /* clang_attribute_ext_h */



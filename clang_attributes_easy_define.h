//
//  clang_attributes_easy_define.h
//  MEngine
//
//  Created by liuxiang on 2018/2/23.
//  Copyright © 2018年 6hao. All rights reserved.
//

//  all support usage:
//  http://clang.llvm.org/docs/AttributeReference.html
//  https://clang.llvm.org/docs/LanguageExtensions.html
#pragma once
#ifndef clang_attributes_easy_define_h
#define clang_attributes_easy_define_h



// Optional of course.
#if !defined(__has_builtin)
// Compatibility with non-clang compilers.
#define __has_builtin(x) 0
#endif




// Constructor
// The annotated function will be called before 'main', but after 'load'.
// @num: shoule be larger than 100, 0-100 are reserved for the system.
// Usage: Use this macro before a function declare
#define ATTR_CONSTRUCTOR_PRIORITY(num) __attribute__((constructor(num)))
#define ATTR_CONSTRUCTOR  ATTR_CONSTRUCTOR_PRIORITY(150)

// Destructor
#define ATTR_DESTRUCTOR  __attribute__((destructor))


// Depre-cated
// Once the annotated function was used, the compiler will show the |description| with compiled warning.
// Usage: Use this macro after a function declaration.
#define ATTR_DEPRECATED(description) __attribute__((deprecated(description)))


// Unavailable
// Once annotated function was used, the compiler will show the |description| with compiled ERROR.
// Usage: after the function's declaration.
#define ATTR_UNAVAILABLE(description) __attribute__((unavailable(description)))


// Cleanup
// After the annotated variable‘s scope, will invoke the pFunction.
// Usage: Uss this macro after a variable's declaration.
#define ATTR_CLEANUP(pFunction) __attribute__((cleanup(pFunction), unused))


// Subclassing-restricted
// This attribute can be added to an Objective-C @interface declaration to ensure that this class cannot be subclassed.
// Usage: before a class declaration.
#define ATTR_SUBCLASS_RESTRICTED __attribute__((objc_subclassing_restricted))


// Require super method called.
// Usage: after the function's declaration.
#define ATTR_REQUIRE_SUPER  __attribute__((objc_requires_super))


// Boxable(Syntactic-Suger)
// Structs and unions marked with the objc_boxable attribute can be used with the Objective-C boxed expression syntax, @(...).
// Usage: This attribute can only be placed on a declaration of a trivially-copyable struct or union:
#define ATTR_BOXABLE __attribute__((objc_boxable))


// Method family.
// Many methods in Objective-C have conventional meanings determined by their selectors.
// It is sometimes useful to be able to mark a method as having a particular conventional meaning despite not
// having the right selector, or as not having the conventional meaning that its selector would suggest.
// For these use cases, we provide an attribute to specifically describe the “method family” that a method belongs to.
// Usage: __attribute__((objc_method_family(X))), where X is one of none, alloc, copy, init, mutableCopy, or new.
// This attribute can only be placed at the end of a method declaration:
#define ATTR_METHOD_FAMILY(x) __attribute((objc_method_family(x)))


// Runtime name.
// By default, the Objective-C interface or protocol identifier is used in the metadata name for that object.
// The objc_runtime_name attribute allows annotated interfaces or protocols to use the specified string argument in
// the object’s metadata name instead of the default name.
// Usage: This attribute can only be placed before an @protocol or @interface declaration.
// NOTE:  Will be a good idea to create obfuscated code.
#define ATTR_RUNTIME_NAME(name) __attribute__((objc_runtime_name(name)))


// Runtime visible.
// This attribute specifies that the Objective-C class to which it applies is visible to the Objective-C runtime
// but not to the linker. Classes annotated with this attribute cannot be subclassed and cannot have categories defined for them.
#define ATTR_RUNTIME_VISIBLE    __attribute__((objc_runtime_visible))


#endif /* clang_attributes_easy_define_h */




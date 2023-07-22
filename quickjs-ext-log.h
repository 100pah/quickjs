#ifndef QUICKJS_EXT_LOG_H
#define QUICKJS_EXT_LOG_H

#ifdef QUICKJS_EXT_LOG_LEVEL_DEBUG

#define QUICKJS_EXT_LOG_TAG "QJS"

#ifdef QUICKJS_EXT_PLATFORM_ANDROID

#include <android/log.h>
// Caveat: QUICKJS_EXT_PLATFORM_ANDROID must be quickjs.a/so private,
// otherwise printf in other code will be override.
#define printf(FMT, ...) \
        __android_log_print(ANDROID_LOG_DEBUG, QUICKJS_EXT_LOG_TAG, "(%s:%d) " FMT, __FILE__, __LINE__, ## __VA_ARGS__)

#endif // QUICKJS_EXT_PLATFORM_ANDROID

#endif // QUICKJS_EXT_LOG_LEVEL_DEBUG

#endif // QUICKJS_EXT_LOG_H

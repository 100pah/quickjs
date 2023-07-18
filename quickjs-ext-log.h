// FIXME: rewrite this file.

#ifndef QUICKJS_EXT_LOG_H
#define QUICKJS_EXT_LOG_H

#define QUICKJS_EXT_LOG_TAG "QJS"

#ifdef QUICKJS_EXT_LOG_LEVEL_DEBUG

#ifdef QUICKJS_EXT_PLATFORM_ANDROID
#include <android/log.h>
#define QJSEXT_LOGD(FMT, ...) \
        __android_log_print(ANDROID_LOG_DEBUG, QUICKJS_EXT_LOG_TAG, "(%s:%d) " FMT, __FILE__, __LINE__, ## __VA_ARGS__)

#else // !QUICKJS_EXT_PLATFORM_ANDROID
#include <stdio.h>
#define QJSEXT_LOGD(FMT, ...) \
        printf("[DEBUG %s] (%s:%d) " FMT "\n", QUICKJS_EXT_LOG_TAG, __FILE_NAME__, __LINE__, ## __VA_ARGS__)

#endif // QUICKJS_EXT_PLATFORM_ANDROID

#else // !QUICKJS_EXT_LOG_LEVEL_DEBUG
#define QJSEXT_LOGD(FMT, ...) do {} while(0)

#endif // QUICKJS_EXT_LOG_LEVEL_DEBUG

#endif // QUICKJS_EXT_LOG_H

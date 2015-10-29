#ifndef _GAME_UTILS_LOGGING_H_
#define _GAME_UTILS_LOGGING_H_ 1

#include <stdio.h>

/**
 * Default logging level will be INFO
 */
#ifndef LOGLEVEL
#define LOGLEVEL 5
#endif

#if LOGLEVEL > 5
    #if LOGPOSITION
        #define log_trace(M, ...) fprintf(stderr, "[TRACE] " M " at %s (%s:%d)\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__)
    #else
        #define log_trace(M, ...) fprintf(stderr, "[TRACE] " M "\n", ##__VA_ARGS__)
    #endif
#else
#define log_trace(M, ...)
#endif

#if LOGLEVEL > 4
    #if LOGPOSITION
        #define log_debug(M, ...) fprintf(stderr, "[DEBUG] " M " at %s (%s:%d)\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__)
    #else
        #define log_debug(M, ...) fprintf(stderr, "[DEBUG] " M "\n", ##__VA_ARGS__)
    #endif
#else
#define log_debug(M, ...)
#endif

#if LOGLEVEL > 3
    #if LOGPOSITION
        #define log_info(M, ...) fprintf(stderr, "[INFO] " M " at %s (%s:%d)\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__)
    #else
        #define log_info(M, ...) fprintf(stderr, "[INFO] " M "\n", ##__VA_ARGS__)
    #endif
#else
#define log_info(M, ...)
#endif

#if LOGLEVEL > 2
     #if LOGPOSITION
        #define log_warn(M, ...) fprintf(stderr, "[WARN] " M " at %s (%s:%d)\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__)
    #else
        #define log_warn(M, ...) fprintf(stderr, "[WARN] " M "\n", ##__VA_ARGS__)
    #endif
#else
#define log_warn(M, ...)
#endif

#if LOGLEVEL > 1
      #if LOGPOSITION
        #define log_error(M, ...) fprintf(stderr, "[ERROR] " M " at %s (%s:%d)\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__)
    #else
        #define log_error(M, ...) fprintf(stderr, "[ERROR] " M "\n", ##__VA_ARGS__)
    #endif
#else
#define log_error(M, ...)
#endif

#if LOGLEVEL > 0
      #if LOGPOSITION
        #define log_fatal(M, ...) fprintf(stderr, "[FATAL] " M " at %s (%s:%d)\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__)
    #else
        #define log_fatal(M, ...) fprintf(stderr, "[FATAL] " M "\n", ##__VA_ARGS__)
    #endif
#else
#define log_fatal(M, ...)
#endif

#endif // UTILS_LOGGING_H

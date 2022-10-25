#ifndef BASE_UTILS_LOGGER_H
#define BASE_UTILS_LOGGER_H

#define C_RESET  "\x1B[0m" // White (Default)
#define C_DEBUG  "\x1B[32m" // Green
#define C_INFO  "\x1B[36m" // Light-Blue
#define C_WARN  "\x1B[33m" // Yellow
#define C_ERROR  "\x1B[31m" // Red

#include <stdio.h>
#include <stdarg.h>

#define log_debug(M, ...) fprintf(stderr, "[%sDEBUG%s]\t - " M "\n", C_DEBUG, C_RESET, ##__VA_ARGS__)
#define log_info(M, ...) fprintf(stderr, "[%sINFO%s]\t - " M "\n", C_INFO, C_RESET, ##__VA_ARGS__)
#define log_warn(M, ...) fprintf(stderr, "[%sWARN%s]\t - " M "\n", C_WARN, C_RESET, ##__VA_ARGS__)
#define log_err(M, ...) fprintf(stderr, "[%sERROR%s]\t - " M "\n", C_ERROR, C_RESET, ##__VA_ARGS__)

#define log_debug_at(M, ...) fprintf(stderr, "[%sDEBUG%s]\t%s(%d)\ - " M "\n", C_DEBUG, C_RESET, __FILE__, __LINE__, ##__VA_ARGS__)
#define log_info_at(M, ...) fprintf(stderr, "[%sINFO%s]\t%s(%d)\t - " M "\n", C_INFO, C_RESET, __FILE__, __LINE__, ##__VA_ARGS__)
#define log_err_at(M, ...) fprintf(stderr, "[%sERROR%s]\t%s(%d)\t - " M "\n", C_ERROR, C_RESET, __FILE__, __LINE__, ##__VA_ARGS__)
#define log_warn_at(M, ...) fprintf(stderr, "[%sWARN%s]\t%s(%d)\t - " M "\n", C_WARN,  C_RESET, __FILE__, __LINE__, ##__VA_ARGS__)

#endif
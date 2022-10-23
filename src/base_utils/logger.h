#ifndef BASE_UTILS_LOGGER_H
#define BASE_UTILS_LOGGER_H

#include <stdio.h>

#define LOGLEVEL LOGLEVEL_DEBUG

enum {
    LOGLEVEL_DEBUG,
    LOGLEVEL_INFO,
    LOGLEVEL_WARNING,
    LOGLEVEL_CRITICAL
};

char const * log_level_strings [] = { "DEBUG", "INFO", "WARN", "CRITICAL" };

extern char const * log_level_strings[];

#define log_at(level, fmt, ...) \
    do { if (level <= LOGLEVEL) fprintf(stdout, "[%s] - " fmt "\t(function: %s in file %s at line %d)\n", log_level_strings[level], __VA_ARGS__, __func__, __FILE__, __LINE__); } while (0)

#define log(level, fmt, ...) \
    do { if (level <= LOGLEVEL) fprintf(stdout, "[%s] - " fmt, log_level_strings[level], __VA_ARGS__); } while (0)

#define LOG_CRITICAL(fmt, ...) log(LOGLEVEL_CRITICAL, fmt, __VA_ARGS__)
#define LOG_WARNING(fmt, ...) log(LOGLEVEL_WARNING, fmt, __VA_ARGS__)
#define LOG_INFO(fmt, ...) log(LOGLEVEL_INFO, fmt, __VA_ARGS__)
#define LOG_DEBUG(fmt, ...) log(LOGLEVEL_DEBUG, fmt, __VA_ARGS__)

#define LOG_AT_CRITICAL(fmt, ...) log_at(LOGLEVEL_CRITICAL, fmt, __VA_ARGS__)
#define LOG_AT_WARNING(fmt, ...) log_at(LOGLEVEL_WARNING, fmt, __VA_ARGS__)
#define LOG_AT_INFO(fmt, ...) log_at(LOGLEVEL_INFO, fmt, __VA_ARGS__)
#define LOG_AT_DEBUG(fmt, ...) log_at(LOGLEVEL_DEBUG, fmt, __VA_ARGS__)


#endif
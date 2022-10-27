#ifndef BASE_UTILS_CHECK_H
#define BASE_UTILS_CHECK_H

#include <string.h>
#include <stdlib.h>

#ifndef MSVC_VER
// Makro for error handling
#define CHECK(X) ({int __val = (X); (__val ==-1 ?\
                    ({fprintf(stderr, "ERROR (" __FILE__ ":%d) --%s\n"\
                    , __LINE__,strerror(errno)); \
                    exit(-1);}) : __val);})

// Makro for error handling that prints a custom message and exits the program with the specified errorcode
#define CHECKV(X, Message, exitcode) ({int __val = (X); (__val ==-1 ?\
                    ({fprintf(stderr, "%s\n", Message); \
                    exit(exitcode);}) : __val);})
#endif
#endif
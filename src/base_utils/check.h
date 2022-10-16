#ifndef BASE_UTILS_CHECK_H
#define BASE_UTILS_CHECK_H

// Makro for error handling
#define CHECK(X) ({int __val = (X); (__val ==-1 ?\
                    ({fprintf(stderr, "ERROR (" __FILE__ ":%d) --%s\n"\
                    , __LINE__,strerror(errno)); \
                    exit(-1);-1;}) : __val);})

#endif
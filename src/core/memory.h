#ifndef CORE_MEMORY_H_
#define CORE_MEMORY_H_

#define new(type) \
malloc(sizeof(type))

#define delete(obj) \
free(obj)

#endif
#include "base_utils_examples.h"

#include "base_utils.h"

static int failingFunction()
{
    return -1;
}

void checkv_example()
{
#ifndef MSVC_VER
    CHECKV(-1, "Something went wrong :/\n", 64);
#endif
}


#pragma once
#include <stddef.h>
#include <sys/types.h>

struct timespec {
    long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec* req, struct timespec* rem);
unsigned int sleep(unsigned int sec);

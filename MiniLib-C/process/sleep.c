#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int result = syscall(35, req, rem);
    if(result >= 0)
        return result;
		errno = -result;
    return -1;
}

unsigned int sleep(unsigned int seconds) {
    struct timespec req = {seconds, 0};
    struct timespec rem = {0, 0};

    int result = nanosleep(&req, &rem);

    if (result == -1)
        return rem.tv_sec;

    return 0;
}
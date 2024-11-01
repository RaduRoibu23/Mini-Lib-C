#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
    int r = syscall(77,fd, length);
    if (r >= 0) {
    return r;
        }
    errno = -r;
    return -1;
}


#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
    int r = syscall(3, fd);
    if (r < 0) {
        errno = -r;
        return -1;
    }
    return r;
}

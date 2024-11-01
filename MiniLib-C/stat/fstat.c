#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
    int ret = syscall(5, fd, st); 

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

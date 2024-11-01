#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int r = syscall(76,path, length);
    if (r >= 0) 
        return r;
    errno = -r;
    return -1;
}

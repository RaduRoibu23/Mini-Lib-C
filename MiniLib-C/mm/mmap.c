#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

	void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
	{
		long ret = syscall(9, addr, length, prot, flags, fd, offset);
		if (ret >= 0) 
			return (void*)ret;
		errno = -ret;
		return MAP_FAILED;
	}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long ret = syscall(25, old_address, old_size, new_size, flags);
	if (ret >= 0) 
		return (void*)ret;
	errno = -ret;
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	int ret = syscall(11, addr, length);
	if (ret >= 0)
		return ret;
	errno = -ret;
	return -1;
}

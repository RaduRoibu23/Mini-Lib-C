#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int puts(const char* str) {
    int result = write(1, str, strlen(str));
    write(1, "\n", 1);
    if (result >= 0) 
        return result;
    errno = -result;
    return -1;

}

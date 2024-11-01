#include <string.h>
char *strcpy(char *destination, const char *source)
{
    char *p = destination;
    while (1) {
        if (*source == '\0')
            break;
        *p = *source;
        p++;
        source++;
    }
    *p = '\0';
    return destination;
}
char *strncpy(char *destination, const char *source, size_t len)
{
    char *p = destination;
    while (1) {
        if (len == 0 || *source == '\0') {
            break;
        }
        *p++ = *source++;
        len--;
    }
    while (1) {
        if (len == 0) {
            break;
        }
        *p++ = '\0';
        len--;
    }
    return destination;
}
char *strcat(char *destination, const char *source)
{
    char *p = destination;
    while (1) {
        if (*p == '\0') {
            break;
        }
        p++;
    }
    while (1) {
        *p = *source;
        p++;
        source++;
        if (*source == '\0') {
            break;
        }
    }
    *p = '\0';
    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    char *p = destination;
    while (*p != '\0') {
        p++;
    }

    while (*source != '\0' && len > 0) {
        *p = *source;
        p++;
        source++;
        len--;
    }
    *p = '\0'; 
    return destination;
}

int strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }

    return *str1 - *str2;
}
int strncmp(const char *str1, const char *str2, size_t len) {
    while (len > 0) {
        if (*str1 == '\0' || *str1 != *str2) {
            return (unsigned char)(*str1) - (unsigned char)(*str2);
        }
        str1++;
        str2++;
        len--;
    }
    return 0;
}


size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c) {
    while (1) {
        if (*str == (char)c) {
            return (char *)str;
        }
        if (*str == '\0') {
            return NULL;
        }
        str++;
    }
}


char *strrchr(const char *str, int c) {
    char *last_p = NULL;

    while (1) {
        if (*str == (char)c) {
            last_p = (char *)str;
        }
        if (*str == '\0') {
            return last_p;
        }
        str++;
    }
}


char *strstr(const char *haystack, const char *needle) {
    while (1) {
        const char *h = haystack;
        const char *n = needle;

        while (*h == *n && *n != '\0') {
            h++;
            n++;
        }
        if (*n == '\0') {
            return (char *)haystack;
        }
        if (*h == '\0') {
            return NULL;
        }
        haystack++;
    }
}

char *strrstr(const char *haystack, const char *needle)
{
    if (!*needle) {
        return (char *)(haystack + strlen(haystack));
    }
    char *r = NULL;
    char *p;
    p = strstr(haystack, needle);
    while (p != NULL) {
        r = p;
        p = strstr(p + 1, needle);
    }
    return r;
}
//https://aticleworld.com/how-to-use-memcpy-and-how-to-write-your-own-memcpy/
void *memcpy(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    const char *src = (const char *)source;
    if (dest < src) {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else if (dest > src) {
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }

    return destination;
}
//https://stackoverflow.com/questions/12038269/code-of-memmove
void *memmove(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    const char *src = (const char *)source;
    if (dest == src) {
        return destination;
    } else if (dest < src) {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else {
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }
    return 0;   
}


void *memset(void *source, int value, size_t num)
{
    unsigned char *p = (unsigned char *)source;
    unsigned char v = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        p[i] = v;
    }
    return source;
}
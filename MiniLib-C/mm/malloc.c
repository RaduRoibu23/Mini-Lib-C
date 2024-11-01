
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>


void *malloc(size_t size) {
    void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (p == MAP_FAILED) {
        return NULL;
    }
    mem_list_add(p, size);
    return p;
}

void *calloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void *p = malloc(total_size);
    if (p != NULL) {
        memset(p, 0, total_size);
    }
    mem_list_add(p, total_size);
    return p;
}

void free(void *ptr) {
    struct mem_list *item = mem_list_find(ptr);
    if (item == NULL) {
        return;
    }
    munmap(ptr, item->len);
    mem_list_del(item->start);
}

void *realloc(void *ptr, size_t size) {
    void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (p == MAP_FAILED) {
        return NULL;
    }
    memcpy(p, ptr, size);
    return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void *p = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (p == MAP_FAILED) {
        return NULL;
    }
    memcpy(p, ptr, total_size);
    return p;
}

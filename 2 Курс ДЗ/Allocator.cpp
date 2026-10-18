#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    unsigned char *memory;
    size_t capacity;
    size_t used;
} Arena;

Arena arena_create(size_t capacity) {
    Arena a = {0};
    a.memory =  static_cast<unsigned char *>(malloc(capacity));
    if (a.memory != NULL) {
        a.capacity = capacity;
    }
    return a;
}

void *arena_alloc(Arena *a, size_t size, size_t alignment) {
    if (a == NULL || a->memory == NULL ||
        alignment == 0 || (alignment & (alignment - 1)) != 0) {
        return NULL; // alignment должна быть степенью двойки
    }

    uintptr_t address = (uintptr_t)(a->memory + a->used);
    size_t padding = (size_t)(-address & (alignment - 1));

    if (padding > a->capacity - a->used) return NULL;
    size_t start = a->used + padding;

    if (size > a->capacity - start) return NULL;

    a->used = start + size;
    return a->memory + start;
}

void arena_reset(Arena *a) {
    if (a != NULL) a->used = 0; // сбросить все выделения разом
}

void arena_destroy(Arena *a) {
    if (a != NULL) {
        free(a->memory);
        *a = (Arena){0};
    }
}
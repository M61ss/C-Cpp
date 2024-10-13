#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

void map(void *xs, size_t n, size_t size, void (*f)(void *)) {
    // Converting to bytes so that we can increment by size
    uint8_t *xs_as_bytes = (uint8_t *)xs;
    for (size_t i = 0; i < n; i++) {
        // Using pointer arithmetic to get the address of the ith element
        f(&xs_as_bytes[i * size]);
    }
}

void square(void *x) {
    int *p = x;
    *p = *p * *p;
}

int main() {
    int xs[] = {1, 2, 3, 4, 5};
    map(xs, 5, sizeof(int), square);
    for (size_t i = 0; i < 5; i++) {
        printf("%d\n", xs[i]);
    }

    return 0;
}
#include <stdio.h>

#define ARRAY_LEN(a) (sizeof a / sizeof a[0])

int main(void) {
    int a = 1;
    int xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *xs_ptr = xs;

    printf("sizeof(int): %zu\n", sizeof(int));
    printf("sizeof(a): %zu\n", sizeof a);
    printf("sizeof(xs_ptr): %zu\n", sizeof xs_ptr);

    // THIS WORKS ONLY FOR ARRAYS STATICALLY ALLOCATED
    printf("sizeof(xs): %zu\n", sizeof xs);
    printf("lenght(xs): %zu\n", ARRAY_LEN(xs));

    return 0;
}
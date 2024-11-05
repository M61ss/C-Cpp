#include <stdlib.h>
#include <stdio.h>

int compar(const void *x1, const void *x2) {
    return (*(int *)x1) - (*(int *)x2);
}

int main(void) {
    int xs[] = {1, 5, 3, 2, 4, 74, 32, 11, 7, 10};

    for(int i = 0; i < 10; i++) {
        printf("%d\n", xs[i]);
    }
    printf("-----------------------------------\n");

    qsort(xs, 10, sizeof(int), compar);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", xs[i]);
    }

    return 0;
}
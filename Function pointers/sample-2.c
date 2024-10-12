#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool even(int a) {
    return a % 2 == 0;
}

void print_if(int xs[10], bool (*predicate)(int)) {
    for (int i = 0; i < 10; i++) {
        if (predicate(xs[i])) {
            printf("%d\n", xs[i]);
        }
    }
}

int main(void) {
    int xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    print_if(xs, even);

    return 0;
}
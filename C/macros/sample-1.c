#include <stdio.h>

#define ADD(x, y) ((x) + (y))

#define SUM_RANGE(start, end) {             \
    int sum = 0;                            \
    for (int x = (start); x < (end); x++)     \
        sum += x;                           \
    printf("Sum: %d\n", sum);               \
}

int main() {
    int x = 5 * ADD(2, 3);
    printf("%d\n", x);

    SUM_RANGE(2, 10);

    return 0;
}
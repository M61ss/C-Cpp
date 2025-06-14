#include <stdio.h>
#include <stdarg.h>

int sum_all(int count, ...) {
    va_list ap;
    va_start(ap, count);

    int sum = 0;
    for (int i = 0; i < count; i++) {
        int x = va_arg(ap, int);
        sum += x;
    }

    va_end(ap);
    return sum;
}

int main(void) {
    printf("%d\n", sum_all(4,3,6,5,7,8));    

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main(void) {
    int (*f)(int, int) = NULL;
    int a = 10, b = 20;
    
    f = add;
    printf("add: %d\n", f(a, b));

    return 0;
}
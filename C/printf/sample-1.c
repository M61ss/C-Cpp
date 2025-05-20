#include <stdio.h>

int main() {
    int a = 1;

    printf("%d\n", -32);
    printf("%u\n", 32);
    printf("%f\n", 42.42);
    printf("%p\n", &a);
    printf("%c\n", 'a');
    printf("%s\n", "hello");
    printf("%%\n");
    printf("%e\n", 139862385.218487);
        
    return 0;
}
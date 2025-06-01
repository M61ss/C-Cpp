#include <stdio.h>

int main() {
    int a = 1;

    printf("%d\n", -32);                // Data types
    printf("%u\n", 32);
    printf("%f\n", 42.42);
    printf("%p\n", &a);
    printf("%c\n", 'a');
    printf("%s\n", "hello");
    printf("%%\n");
    printf("%g\n", 139862385.218487);

    printf("##%5d\n", 634);             // Left padding
    printf("%-5d##\n", -32);            // Right padding

    printf("%05d\n", 32);               // 0 padding
    printf("%05d\n", -32);

    printf("% d\n", -32);               // It puts a space if number is positive
    printf("% d\n", 32);
    printf("%+d\n", 32);                // It prints always the sign
    printf("%+d\n", -32);

    return 0;
}
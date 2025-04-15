#include <stdio.h>
#include <stdint.h>     // Useful to define specific memory size of variables

int main(void)
{
    int32_t a = 32;             // Decimal
    int b = 0xffaa33;           // Hexadecimal
    int c = 0755;               // Octal
    int d = 0b010001110101;     // Binary

    printf("%d\n", a);
    printf("%x\n", b);
    printf("%o\n", c);
    printf("%b\n", d);

    return 0;
}
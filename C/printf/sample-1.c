#include <stdio.h>

int main() {
    printf("%d\n", -32);                // Int
    printf("%u\n", 32);                 // Unsigned int
    printf("%f\n", 42.42);              // Float
    printf("%lf\n", 42.42);             // Double
    int a = 1;                                  // Pointer
    printf("%p\n", &a);                 
    printf("%c\n", 'a');                // Char
    printf("%s\n", "hello");            // String
    printf("%%\n");                     // %
    printf("%g\n", 139862385.218487);   // Scientific 
    long int l = 8654886149842631684;           // Long 
    printf("%ld\n", l);
    long long int ll = 8654886149842631684;     // Long long
    printf("%lld\n", ll);               
    short s = 123;                              // Short
    printf("%hd\n", s);
    char c = 12;                                // Numeric char
    printf("%hhd\n", c);                // It prints chars like decimals
    size_t n = 5746;                            // Platform indipendent unsigned int
    printf("%zu\n", n);     

    printf("%.3f\n", 42.42654651);      // Precision
    printf("%.*f\n", 5, 42.42654651);   // Precision by parameter

    printf("##%5d\n", 634);             // Left padding
    printf("%-5d##\n", -32);            // Right padding
    printf("%*d\n", 5, 42);             // Padding by parameter
    printf("#%*d\n", 8, 42);
    printf("%*.*f\n", 3, 5, 42.42654651);

    printf("%05d\n", 32);               // 0 padding
    printf("%05d\n", -32);

    printf("% d\n", -32);               // It puts a space if number is positive
    printf("% d\n", 32);
    printf("%+d\n", 32);                // It prints always the sign
    printf("%+d\n", -32);

    return 0;
}
#include <stdio.h>

int main(void)
{
    char *literal = "Literal string";
    char array[] = "Array string";
    
    array[0] = 'K';
    // literal[0] = 'K';    It produces compile error

    printf("%s\n", literal);
    printf("%s\n", array);

    return 0;
}
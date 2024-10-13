#include <stdio.h>

static int case_convert[] = {
    ['a'] = 'A',
    ['b'] = 'B',
    ['c'] = 'C'
};

int main(void) {
    printf("%c\n", case_convert['a']);
    printf("%c\n", case_convert['b']);
    printf("%c\n", case_convert['c']);

    return 0;
}
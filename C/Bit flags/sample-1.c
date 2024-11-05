#include <stdlib.h>
#include <stdio.h>

typedef enum {
    FLAG_A = 1 << 0,
    FLAG_B = 1 << 1,
    FLAG_C = 1 << 2
} t_flag;

void print_flags(t_flag flags) {
    if (flags & FLAG_A) {
        printf("FLAG_A is set\n");
    }
    if (flags & FLAG_B) {
        printf("FLAG_B is set\n");
    }
    if (flags & FLAG_C) {
        printf("FLAG_C is set\n");
    }
}

int main() {
    t_flag flags = FLAG_A | FLAG_C;
    print_flags(flags);
    return 0;
}
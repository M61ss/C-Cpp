#include <stdio.h>
#include <stdbool.h>

enum tag {
    TAG_INT,
    TAG_FLOAT,
    TAG_BOOL,
};

struct dynamic {
    enum tag tag;
    union {
        int i;
        float f;
        bool b;
    } value;
    // The name of the union is required by standard ISO
    // Anyway, gcc compiles also without specifying it (and this make less verbose to access union's fields)
};

int main(void) {
    struct dynamic d;
    printf("Size of struct dynamic: %zu\n", sizeof d);

    d.tag = TAG_INT;
    d.value.i = 42;

    switch (d.tag) {
        case TAG_INT:
            printf("Value: %d\n", d.value.i);
            break;
        case TAG_FLOAT:
            printf("Value: %f\n", d.value.f);
            break;
        case TAG_BOOL:
            printf("Value: %s\n", d.value.b ? "true" : "false");
            break;
    }

    return 0;
}
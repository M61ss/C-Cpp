#include <stdio.h>

struct foo {
    int first_4 : 4;
    int next_4 : 4;
    int alone : 1;
    int rest : 7;
};

int main(void) {
    printf("Size of foo: %zu\n", sizeof(struct foo));

    struct foo f;
    // You can check that the size of fields of the struct is exactly 
    // the size of the bit field
    //
    // f.first_4 = 3;
    // f.next_4 = 7;
    // f.alone = 1;
    // f.rest = 127;

    int fd = open("file");
    read(fd, &f, sizeof(struct foo));   // It reads data and puts bits in the
                                        // corrispondent struct fields
    
    close(fd);
    return 0;
}
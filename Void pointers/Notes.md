## Void pointers

A pointer is a variable that contains a memory address. So, by this definition:

```c
int main(void) {
    int a = 3;
    void *p = &a;

    printf("%p\n", p);

    return 0;
}
```

This code compiles and print the address of the variable `a`. There are no errors because we store in `p` an address without providing any content since a `void` variable cannot store any data. Otherwise, since a `void*` is a pointer, it can contain an address which points somewhere.


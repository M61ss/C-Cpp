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

### Note about "sample-2.c"

When casting to `uint8_t*` we are casting the pointer, but not its content. To cast a pointer means to tell C that each element of the `xs` array points to something that is 1 byte long, but C does not modify the allocated memory for array's elements and, consequentially, their content remain untouched; then, there is no information leakage. This feature is very powerful because allows us to work with any data without taking care of type, but knowing its size.

> [**Return to the index**](../Advanced%20C.md)

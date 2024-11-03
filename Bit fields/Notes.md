## Bit fields

Maybe we need to read from a file some data which are composed of some field, each of those has a specific meaning or function.

In C is possible to take advantage of `struct`:

```c
struct foo {
    int first_4 : 4;
    int next_4 : 4;
    int alone : 1;
    int rest : 7;
}
```

Where `:` is an operator which specifies that variable's size in bit. So, `first_4` and `next_4` are 4 bit large, `alone` 1 and `rest` 7, even if they are decleared as `int`.
\
This `struct` occupies exactly 2 bytes.

Using this data structure in C is powerful working with bit fields, expecially reading or writing on files data with a knwon format.

It is also possible to use existing data types to compose this kind of `struct`:

```c
struct foo {
    uint8_t first;
    uint8_t second;
    uint16_t third;
}
```

This is 4 bytes large.


> [**Return to the index**](../Advanced%20C.md)

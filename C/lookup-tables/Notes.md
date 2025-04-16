## Lookup tables pattern

Lookup tables try to emulate Java's HashTable or Python dictionary.

All we need is to create an `enum` for the mapping and a `static` array for elements of any type. Lookup tables work also with `struct`.

_Example_:

```c
enum foo {
    foo_2 = 0,
    foo_3,
    foo_4
};

static int squares[] = {
    9,
    4,
    16
}
```

Then, if we try to access `squares`' fields with `foo`'s value, we obtain corresponding values.
\
However, since it is not really useful and readable, it is possible to use this syntax:

```c
static int squares[] = {
    [foo_3] = 9,
    [foo_2] = 4,
    [foo_4] = 16
}
```

We can assign each element to a specific identifier and with a custom order.

> [!TIP]
>
> In the last example `enum` is no longer necessary. To build cleaner lookup tables, it is advised to avoid `enum`.

### Dimensions

Be careful about the dimension of identifiers because they may occupy a lot of memory in case they are too big. A good practice is to make them not larger than 1 byte.

> [**Return to the index**](../../Index.md)

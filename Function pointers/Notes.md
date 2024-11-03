## Function pointers <!-- omit from toc -->

- [Function type](#function-type)
- [`typedef`](#typedef)

Let's consider a function:

```c
int fun(int x, int y) {
    return x + y;
}
```

A function is just a piece of code located somewhere in the memory. So, it has its own address, provided by a pointer.

### Function type

The function type is a special data type that can contain a function pointer, like `fun`:

```c
int (*f)(int, int) = fun;
```

Where:

- `f` is the name of the variable.
- `(int, int)` are types of parameters of the function. Note that is not required a name for those.
- `fun` is the function that we assign to this function type.

### `typedef`

Rename a function pointer:

```c
typedef int (*custom_name)(int, int);
```

> [**Return to the index**](../Advanced%20C.md)

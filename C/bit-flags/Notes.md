## Bit flags

We can imagine a situation in which we need to work with a function taht has some boolean arguments:

```c
int f(int x, bool add, bool square, bool multiply)
```

These function arguments in large software increase and it is not long term mantainable. Every time we need to add an option, we must modify the function definition.
\
It is possible to simplify a lot this mechanism with bit flags.  

All we need is a `typedef` and some defines:

```c
typedef unsigned int t_flag;
#define FLAG_A (1 << 0)
#define FLAG_B (1 << 1)
#define FLAG_C (1 << 2)
```

This way we defined a new type `t_flag` useful to represent the data type which should contains a value, for example, to compare to defined flags.

```c
int f(int x, t_flag flag)
```

With bitwise operators we can extract information from `flag`. 

> [**Return to the index**](../../Index.md)

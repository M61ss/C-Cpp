## Tagged union

### Dynamic typing

It is possible to implement in C dynamic typing using `union`.

```c
enum tag {
    TAG_BOOL,
    TAG_INT,
    TAG_FLOAT
};

struct dynamic {
    enum tag tag;
    union {
        bool b;
        int i;
        float f;
    } value;
};
```

It is important to notice that this is only a strategy to manually implement something that doesn't exist in C; precisely for this reason, there could be several ways to obtain the same result. This one is better because it saves memory. 
\
We can check with a `sizeof` that, for example, the `union` uses 8 bytes, but if we replace it with a `struct`, then it will occupy 16 bytes. 

### Other uses

Since dynamic typing looks cumbersome in C, there are may other ways to exploit this data structure.

An example, it is useful if we want to store information which can change cathegory keeping memory about its type. 

> [**Return to the index**](../../Index.md)

# Function with a variable arguments number

It is possible to declare functions in C which accept a variable arguments number using macros provided by `stdarg.h`.

The declaration of those functions looks like that:

```C
int foo(int parameter, ...) {
    // ...
}
```

Then, inside the function you need to:

- Declare a list to use as arguments pointer;
- Specify where the variable arguments list starts;
- Specify the data type for every element of the list extracting it from the arguments pointer;
- Specify there the variable arguments list ends.

So:

```C
int foo(int a, int b, ...) {
    va_list ap;
    va_start(ap, b);    // b is the element just before the variable arguments list start

    // ...

    int x = va_arg(ap, int);    // it extract an argument from the head of the list

    // ...

    va_end(ap);
} 
```

> [!IMPORTANT]
>
> If you want to use an argument of that list more than once, you have to save it into a variable. 
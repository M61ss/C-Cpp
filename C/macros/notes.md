# Macros

## Basics

It is important to wrap into parenthesis macros parameters and its entire argument because macros work simply with text replacement. Omitting parenthesis could cause unexpected behaviour in computations. 
\
For example:

```C
// ...
#define ADD(x, y) x + y

int main() {
    int x = 5 * ADD(2, 3);
    printf("%d\n", x);      // it produces 13
    // ...
}
```

```C
// ...
#define MUL(x, y) (x * y)

int main() {
    int x = 5 * ADD(2, 3 + 2);
    printf("%d\n", x);      // it produces 40
    // ...
}
```

So, the correct example should be:

```C
// ...
#define ADD(x, y) ((x) + (y))

int main() {
    int x = 5 * ADD(2, 3);
    printf("%d\n", x);
    // ...
}
```

## Multiline macros

Using multiline macros you need to pay attention to scope. Since macros are simply text replacement, if you have in your function a variable with the same name of another one inside the macro, then you will cause a compile error due to multiple declaration. You need to create an additional scope for the macro.
\
For example:

```c
// ...
#define SUM_RANGE(start, end)               \
    int sum = 0;                            \   // sum declared also here
    for (int x = start; x < (end); x++)     \
        sum += x;                           \
    printf("Sum: %d\n", sum);   
    
int main() {
    int sum = 0;
    SUM_RANGE(2, 10);       // It cause a compile error
    // ...
}
```

The right code is:

```c
// ...
#define SUM_RANGE(start, end) {             \
    int sum = 0;                            \
    for (int x = (start); x < (end); x++)     \
        sum += x;                           \
    printf("Sum: %d\n", sum);               \
}

int main() {
    int sum = 0;
    SUM_RANGE(2, 10);
    // ...
}
```
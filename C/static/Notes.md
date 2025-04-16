## `static`

In C the `static` keyword is used in 2 cases:

- For variables:

  ```c
  int fun() {
    static int count = 0;
    count++;
    return count;
  }
  ```

  Even if `function` has been executed, the value of `a` is kept in memory. So, in this example, every time we call this function `a` is incremented by 1.

- For functions:

  ```c
  static int function() {
    // ...
  }
  ```
  
  This function is visible only by functions in the same file ([translation unit](https://en.wikipedia.org/wiki/Translation_unit_%28programming%29)).

> [**Return to the index**](../../Index.md)

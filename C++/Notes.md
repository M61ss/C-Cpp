# Gold mine

A lot of useful information about C++ can be found [**here**](https://caiorss.github.io/C-Cpp-Notes/) (**very recommended**).

# C++

Assumed basic knowledge of C.

## `main`

Three possible definition of `main`:

- ```c
  int main();
  ```

- ```c
  int main(int argc, char **argv);
  ```

- ```c
  int main(int argc, char **argv, char **environ);
  ```

  Where `**environ` is a vector containing environment variables.

## Variables

C++ supports multiple variables initialization with assignment at same line.

_Example_:

```c
double xx = 3.1515, yy = 3 * xx + 3.0, zz = xx * 2 + yy;
```

```c
double x, y, z;
x = y = z = 3.0;
```

## Literals

- **Integer**: `123456` (or `123'456` since C++14);
- **Unsigned integer**: `123456U` (or `123'456U` since C++14);
- **Exadecimal integer**: `0xFFCA07` (or `0xFF'CA'07` since C++14);
- **Binary integer** (since C++14): `0b00101101` or `0b0010'1101`;
- **Float**: `1555100.9151f` (or `15'55'100.91'25'41f` or `1555'100.912541f` since C++14); 
- **Double** (since C++14): `15'55'100.91'25'41` or `1555'100.912541`;
- **Character**: `C`;
- **Non-printable character**: `\x0F` (exadecimal value!).

## String

- **Multiline strings**: 
  
  ```c
  const char* str1 =
        " => C++98 programming language ; \n"
        " => Rust programming language ; \n"
        " => Forth programming language ; \n"
        " => ADA programming language ; \n"
        ;
  ```

- **Raw string literal**: It supports multiline and characters that are used for escaping sequence such as backward slash (\\) that, in regular strings, needs to be escaped and written as (\\\\):
  
  <!-- ATTENTION: escapes in the following string are needed by Markdown, NOT by C++ -->
  ```c
  const char* windows_path = R"(C:\\Uses\\Dummy\\Path)";
  ```

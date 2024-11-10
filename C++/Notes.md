# Index

- [Index](#index)
- [Gold mine](#gold-mine)
- [C++](#c)
  - [`main`](#main)
    - [`auto`](#auto)
  - [Literals](#literals)
  - [String](#string)
  - [`if-else`](#if-else)
  - [I/O](#io)
  - [Functions](#functions)
    - [Default parameters](#default-parameters)

# Gold mine

A lot of useful information about C++ can be found [**here**](https://caiorss.github.io/C-Cpp-Notes/) (**very recommended**).

# C++

Assumed basical knowledge of C. 

## `main`

Three possible definition of `main`:

- ```c++
  int main();
  ```

- ```c++
  int main(int argc, char **argv);
  ```

- ```c++
  int main(int argc, char **argv, char **environ);
  ```

  Where `**environ` is a vector containing environment variables.

## Variables

C++ supports multiple variables initialization with assignment at same line.

_Example_:

```c++
double xx = 3.1515, yy = 3 * xx + 3.0, zz = xx * 2 + yy;
```

```c++
double x, y, z;
x = y = z = 3.0;
```

### `auto`

The `auto` keyword automatically deduces the type of the variable from its initialization expression. This means that its type cannot be changed by reassignment.
\
No automatic cast is performed on variables declared with `auto`. 

*Example*:

```c++
#include <cmath>

int main()
{
  auto x = 34.0f - sqrt('a' / 3.0);
  int b = x % 2;  // ERROR: the % operand works only with int, but x is double!

  return 0;
}
```

## Literals

> [!IMPORTANT] Data types
>
> Data types are the same of C. 
> \
> In addition, the `bool` data type and all data types defined inside `<stdint.h>` in C++ are built-in.

> [!IMPORTANT] nullptr
>
> In C++ `nullptr` represents a null pointer. It can be assigned or used for comparisons.
> \
> However, it does not replace the usage of `NULL`. Some functions or data types of external libraries, maybe imported from C, requires usage of the macro `NULL` and could not work properly with `nullptr` since their implementations are different.

- **Integer**: `123456` (or `123'456` since C++14);
- **Unsigned integer**: `123456U` (or `123'456U` since C++14);
- **Exadecimal integer**: `0xFFCA07` (or `0xFF'CA'07` since C++14);
- **Binary integer** (since C++14): `0b00101101` or `0b0010'1101`;
- **Float**: `1555100.9151f` (or `15'55'100.91'25'41f` or `1555'100.912541f` since C++14); 
- **Double** (since C++14): `15'55'100.91'25'41` or `1555'100.912541`;
- **Character**: `'C'`;
- **Non-printable character**: `'\x0F'` (exadecimal value!).

## String

- **Multiline strings**: 
  
  ```c++
  const char* str1 =
        " => C++98 programming language ; \n"
        " => Rust programming language ; \n"
        " => Forth programming language ; \n"
        " => ADA programming language ; \n"
        ;
  ```

- **Raw string literal**: It supports multiline and characters that are used for escaping sequence such as backward slash (\\) that, in regular strings, needs to be escaped and written as (\\\\):
  
  ```c++
  const char* windows_path = R"(C:\Uses\Dummy\Path)";
  ```

## `if-else`

`if-else` statements are exactly the same of C. 

Remember ternary operator:

```c
int value = true ? 1 : 0;    // value = 1
value = false ? 1 : 0;       // value = 0
```

Since C++17, in addiction to the possibility of assign a value to a variable, is also possible to declare and assign a variable inside an `if` condition.

*Example*:

```c++
if (FILE* fp = fopen("/tmp/file4.dat", "w"); fp != nullptr) {
    fprintf(fp, "File content 2");
    fclose(fp);
}
```

## I/O

There are 4 I/O functions:

- `std::cout`: prints output on `stdout`.
- `std::cin`: reads input from `stdin`.
- `std::clog`: prints output on `stderr`.
- `std::cerr`: prints output on `stdoerr`.

These functions work with two operators:

- Insertion operator `<<`: it takes elements at its right and inserts them into the output function at its left.
- Extraction operator `>>`: it takes the ouput of the input function at its left and puts it inside the container at its right.

*Example*:

```c++
#include <iostream> 
#include <string> 

double x;
std::cin >> x;
 
std::cout << "Enter x: "; std::cin >> x; std::cout << " => x = " << x << "\n";

std::string user;
std::cout << "Name: "; std::cin >> user; std::cout << " => user is = " << user;
```

To read multiple data from console:

```c++
#include <iostream> 
#include <string> 

int         id, quantity;
double      price;
std::string name;

// Read from console 4 data separated by whitespaces
std::cin >> id >> name >> quantity >> price;
```

Useful to easily read structured data. 

> [!TIP] getline
> 
> To read an entire line (until `\n`) use `std::getline`.

## Functions

An alternative function implementation supported by C++ is:

```c++
auto someFunction(void) -> void {
    std::puts("I am a C++ free function");
    return;       
}
```

Since C++14 is available also this (type inference):

```c++
auto someFunction() {
    std::puts("I am a C++ free function");
    return;       
}
```

### Default parameters

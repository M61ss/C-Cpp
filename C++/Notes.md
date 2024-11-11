# Index

- [Index](#index)
- [Gold mine](#gold-mine)
- [C++ reference](#c-reference)
- [C++](#c)
  - [`main`](#main)
    - [`auto`](#auto)
    - [`static`](#static)
  - [Literals](#literals)
  - [String](#string)
    - [Multiline strings](#multiline-strings)
    - [Raw string literal](#raw-string-literal)
    - [`std::string`](#stdstring)
    - [`std::to_string`](#stdto_string)
    - [Comma separated value (CSV) parser](#comma-separated-value-csv-parser)
  - [Regular expression (Regex)](#regular-expression-regex)
  - [`if-else`](#if-else)
  - [For-range](#for-range)
  - [Functions](#functions)
    - [Default parameters](#default-parameters)
    - [Function overloading](#function-overloading)
  - [Collections](#collections)
    - [Iterator](#iterator)
  - [Stream](#stream)
    - [I/O streams](#io-streams)

# Gold mine

A lot of useful information about C++ can be found [**here**](https://caiorss.github.io/C-Cpp-Notes/) (**very recommended**).

# C++ reference

https://cplusplus.com/reference/

# C++

Assumed basical knowledge of C and OOP. 

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

### `static`

`static` variables or functions are initialized after the first function invocation and keeps their state during successive function invocations. 

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
- **Non-printable character**: `'\x0F'` (exadecimal value!);
- **String literal** (since C++14): to treat string literals as `std::string` (see [String](#string)) you can use this syntax:
  
  ```c++
  // std::string concatenated = "string" + " contatenated";  ERROR: concatenation with `+` is supported only with `std::string`
  std::string concatenated = std::string("string") + " contatenated";   // Verbose
  std::string concatenated = "string"s + " contatenated";   // Compact, equivalent to the previous
  ```

## String

### Multiline strings 
  
  ```c++
  const char* str1 =
        " => C++98 programming language ; \n"
        " => Rust programming language ; \n"
        " => Forth programming language ; \n"
        " => ADA programming language ; \n"
        ;
  ```

### Raw string literal

C++ supports raw string literal which can contain characters that are used for escaping sequence such as backward slash (\\) that, in regular strings, needs to be escaped and written as (\\\\). They can be multiline.
  
```c++
const char* windows_path = R"(C:\Uses\Dummy\Path)";
```

### `std::string`

`std::string` is defined in `<string>` ([C++ reference](http://www.cplusplus.com/reference/string/)). It make easier to manipulate strings since `std::string` is an object with useful methods;

### `std::to_string` 

`std::to_string` is the method to convert a value to a string. It returns a `std::string`. 

### Comma separated value (CSV) parser

> [!WARNING] CSV (comma separated value)
>
> The following CSV parser functions fails for heterogeneous data or when there are quotes characters. It is better to use a proper CSV parser library as CSV is not a standardized data exchange format and has lots of tricky edge cases.

It is important to see an example of implementation of a CSV since it is very used and useful:

```c++
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<double> parseCSVRow(const std::string& line, char delim = ','){
    auto out   = std::vector<double>{};
    auto token = std::string{};
    auto ss    = std::stringstream{line};

    while(std::getline(ss, token, delim)){
      out.push_back(std::stod(token));
    }

    return out;
}

int main(void) {
    std::string raw_data = "100,   200,  400, -100.23, 60.23, 90.32";
    parseCSVRow(raw_data);

    return 0;
}
```

Generic version (see [template]()):

```c++
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

template<class Type = double>
std::vector<Type> parseCSVRowGeneric(const std::string& line, char delim = ',') {
    auto out   = std::vector<Type>{};
    auto token = std::string{};
    auto ss    = std::stringstream{line};
    auto is    = std::stringstream{};
    Type value{};

    while(std::getline(ss, token, delim)){
      // Clear error flags                                                                                                                              
      is.clear();
      // Set is stream value to token                                                                                                                   
      is.str(token);
      // Extract from 'is' stream                                                                                                                       
      is >> value;
      out.push_back(value);
    }

    return out;
}
```

## Regular expression (Regex)

Regex syntax: [ECMAScript syntax - C++ Reference](https://cplusplus.com/reference/regex/ECMAScript/).

Online regex testers:

- [Myregextester.com](https://myregextester.com/).
- [RegExr: Learn, Build & Test RegEx](https://regexr.com/).
- [regex101.com](https://regex101.com/)

See also [\<regex\> - C++ Reference](http://www.cplusplus.com/reference/regex/).

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

## For-range

For-range with literals:

```c++
for(const auto& x: {10, 20, 40, 50, 60}) {
    std::cout << " x = " << x << "\n";
}
```

For-range over a collection:

```c++
std::vector<std::string> xs {"Hello", "world", "C++", "HPC", "awesome"};

// Use const auto& to avoid uncessary copies. Use auto& if there is modification of x instead.
// The const keyword will generate a compiler error if there is any attempt to modify x's value. 
for(const auto& x: xs) {
    std::cout << "word = '" << x << "' size = " << x.size() << "\n";
}
```

> [!WARNING]
>
> If the iterator is a reference, changes on it will reflect on the original collection.

## Functions

An alternative function implementation supported by C++ is (lambda):

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

In C++ it is possible to assign default parameters to functions arguments.

*Example*:

```c++
double someFunction(double x, int n = 4, double z = 3.5)
{
    std::cout << "  x = "  << x
              << " ; n = " << n
              << " ; z = " << z
              << "\n";
    return x * n + 4.0 * z;
}
```

### Function overloading

C++ supports function overloading.

*Example*:

```c++
#include <iostream> 

void show(){
    std::cout << "Call Version0." << "\n";
}

void show(int x){
    std::cout << "Call Version1 with =>" << " x [int] = " << x << "\n";
}

void show(double x){
    std::cout << "Call Version2 with =>" << " x [double] = " << x << "\n";
}
```

## Collections

Data structures are all available in namespace `std` (ex. `std::vector<Type>`, `std::list<Type>`, etc.).

> [!WARNING]
>
> `std::vector<Type>` isn't the best choice working in embedded and robotics because, since resources are limited, to use dynamic resizing reduces performance. It is better to set a fixed size, then resize it only if necessary.
> \
> However, it is possible to reserve memory for a vector using its method `reserve` to prevent to resize it everytime, improving performance.  

### Iterator

```c++
std::vector<std::string> xs {"Hello", "world", "C++", "HPC", "awesome"};

for(std::vector<std::string>::iterator it = xs.begin(); it != xs.end(); ++it){
     std::cout << "word = '" << *it << "' size = " << it->size() << "\n";
}

/** Output: 
    word = 'Hello' size = 5
    word = 'world' size = 5
    word = 'C++' size = 3
    word = 'HPC' size = 3
    word = 'awesome' size = 7 
 */

// ===== OR ===== //

for(auto it = xs.begin(); it != xs.end(); ++it){
     std::cout << "word = '" << *it << "' size = " << it->size() << "\n";
}

/** Output: 
    word = 'Hello' size = 5
    word = 'world' size = 5
    word = 'C++' size = 3
    word = 'HPC' size = 3
    word = 'awesome' size = 7
*/
```

## Stream

Streams in C++ work with two operators:

- Insertion operator `<<`: it takes elements at its right and inserts them into the output stream at its left.
- Extraction operator `>>`: it takes the input from the input stream at its left and puts it inside the container at its right.

For instance, we can want to make a function able to print on whatever output stream depending on our needs:

```c++
#include <iostream> 
#include <iomanip>
#include <sstream>

void printReport(std::ostream& os){
    os << std::setprecision(3);
    os << std::fixed;
    os << std::boolalpha;
    char nl = '\n';
    os << "Report Data" << nl
       << " x = " << 23.123 << nl
       << " d = " << true   << nl
       << " z = " << M_PI   << nl;
    os.flush();
}

int main(void) {
    printReport(std::cout);
    printReport(std::cerr);

    return 0;
}
```

The same mechanism works as well for input stream using `std::istream`.

> [!WARNING] 
>
> C++ uses `<<`, insertion operator, also to change stream settings (ex. `os << std::setprecision(3)`). Contrarwise, Java uses dot notation to invoke stream methods. 

### I/O streams

There are 4 standard I/O stream:

- `std::cout`: prints output on `stdout`.
- `std::cin`: reads input from `stdin`.
- `std::clog`: prints output on `stderr`.
- `std::cerr`: prints output on `stdoerr`.

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
#include <exception>
#include <print>
#include <cpptrace/cpptrace.hpp>
#include <cpptrace/from_current.hpp>

void bar() {
    std::terminate();
}

void foo() { bar(); }

int main() {
    cpptrace::register_terminate_handler();     // It registers an handler to call if the program encounters an std::terminate()
    foo();

    return 0;
}
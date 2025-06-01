#include <print>
#include <cpptrace/cpptrace.hpp>
#include <cpptrace/from_current.hpp>
#include <stdexcept>

void bar() {
    throw std::runtime_error("hello");
}

void foo() { bar(); }

int main() {
    CPPTRACE_TRY {
        foo();
    } CPPTRACE_CATCH(const std::exception &e) {
        cpptrace::from_current_exception().print();
    }

    return 0;
}
#include <iostream>
uint32_t fib(uint32_t num) {
    if (num == 1 || num == 2) return num;
    return fib(num - 2) + fib(num - 1);
}
int main() {
    std::cout << fib(4);
    std::cout << "\n\n";
    std::cout << fib(6);
    return 0;
}
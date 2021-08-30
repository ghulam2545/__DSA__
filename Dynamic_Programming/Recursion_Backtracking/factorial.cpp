#include <iostream>
uint32_t fact(uint32_t num) {
    if (num == 0) return 1;
    return num * fact(num - 1);
}
int main() {
    std::cout << fact(4);
    std::cout << "\n\n";
    std::cout << fact(6);

    return 0;
}
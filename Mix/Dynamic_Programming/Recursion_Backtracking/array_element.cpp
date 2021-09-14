#include <bits/stdc++.h>
using namespace std;

void f1(int num) {
    if (num == 1) {
        std::cout << num << " ";
        return;
    }
    f1(num - 1);
    std::cout << num << " ";
}

constexpr int f2(int num) {
    if (num == 1) {
        return num;
    }
    std::cout << num << " ";
    return f2(num - 1);
}

int main() {
    constexpr int n = 10;
    f1(n);
    std::cout << "\n";
    std::cout << f2(n);
    return 0;
}

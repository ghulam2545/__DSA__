#include <iostream>
#include <vector>

struct sample {
    template <typename T> constexpr const T &max(const T &a, const T &b) { return a > b ? a : b; }
    template <typename T> constexpr const T &min(const T &a, const T &b) { return a > b ? b : a; }
};

constexpr const sum(const int *arr, const int &size) {
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans += arr[i];
    }
    return ans;
}

int main() {
    int *num;
    int m;
    std::cin >> m;
    num = new int[m];
    for (int i = 0; i < m; i++) {
        std::cin >> num[i];
    }
    std::cout << sum(num, m);
    // sample *instance;
    // int a, b;
    // std::cin >> a >> b;
    // std::cout << instance->max(a, b);
    // std::cout << instance->min(a, b);
    // std::cout << "\n\n";
    // ++a;
    // std::cout << a;
    return 0;
}

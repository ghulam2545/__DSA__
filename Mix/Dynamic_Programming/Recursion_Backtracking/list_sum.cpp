#include <ctime>
#include <iostream>
#include <numeric>
using namespace std;
long long sum(int* arr, int size) {
    if (size == 0) return 0;
    return arr[size - 1] + sum(arr, size - 1);
}
int main() {
    srand(time(0));
    const int size = 12;
    int a[size];
    for (size_t i = 0; i < 12; ++i) {
        a[i] = rand() % 100;
    }
    for (size_t i = 0; i < 12; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << accumulate(a, a + 12, 0) << "\n";
    long long ans = sum(a, size);
    cout << ans << "\n";
    return 0;
}
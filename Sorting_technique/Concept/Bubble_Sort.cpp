#include <iostream>
using namespace std;
int* BubbleSort(int* a, int& n);
int main() {
    int num[] = {12, 32, 67, 45, 33, 65, 23, 90};
    int n = sizeof(num) / sizeof(num[0]);

    int* temp = BubbleSort(num, n);
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
}
int* BubbleSort(int* a, int& n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {  // for decreasing chage ">" to "<"
                swap(a[j], a[j + 1]);
            }
        }
    }
    return a;
}

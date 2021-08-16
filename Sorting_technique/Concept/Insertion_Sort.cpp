#include <iostream>
using namespace std;
int* InsertionSort(int* a, int& n);
int main() {
    int num[] = {12, 32, 67, 45, 33, 65, 23, 90};
    int n = sizeof(num) / sizeof(num[0]);

    int* temp = InsertionSort(num, n);
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
}
int* InsertionSort(int* a, int& n) {
    int key;
    for (int i = 1; i < n; i++) {
        key = a[i];
        while (i > 0 && a[i - 1] > key) {  // for decreasing chage ">" to "<"
            a[i] = a[i - 1];
            i--;
        }
        a[i] = key;
    }
    return a;
}

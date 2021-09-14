#include <iostream>
using namespace std;
int* selectionSort(int* a, int size);
int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int& e : ar) {
        cin >> e;
    }
    for (int& e : ar) cout << e << " ";
    cout << "\n\n";
    int* ptr = selectionSort(ar, n);
    for (int i = 0; i < n; i++) {
        cout << ptr[i] << " ";
    }

    return 0;
}

int* selectionSort(int* a, int size) {
    int minInd = 0;
    for (int i = 0; i < size - 1; i++) {
        minInd = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minInd]) {
                minInd = j;
            }
        }
        swap(a[i], a[minInd]);
    }
    return a;
}

/*
9
89 64 78 53 23 19 77 36 29
*/

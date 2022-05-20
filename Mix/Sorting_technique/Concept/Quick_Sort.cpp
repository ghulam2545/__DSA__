#include <iostream>
using namespace std;
int partition(int *arr, int start, int end);
void quickSort(int *arr, int start, int end);
int main() {
    int a[] = {12, 67, 54, 90, 56, 11, 77, 34, 52, 44, 10};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex += 1;
        }
    }
    swap(arr[end], arr[pIndex]);
    return pIndex;
}
void quickSort(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pIndex = partition(arr, start, end);

    for (int i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    quickSort(arr, start, pIndex - 1);
    quickSort(arr, pIndex + 1, end);
}

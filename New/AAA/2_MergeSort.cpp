#include <algorithm>
#include <iostream>
using namespace std;
void MergeSort(int*, int, int);
void Merge(int*, int, int, int);
int main() {
    int data[] = {43, 89, 66, 12, 54, 67, 22};
    int len = sizeof(data) / sizeof(data[0]);
    cout << "Before sort data are : \n";
    for (int i = 0; i < len; ++i) {
        cout << data[i] << " ";
    }
    MergeSort(data, 0, len - 1);
    cout << "\n\nAfter sort data are : \n";
    for (int i = 0; i < len; ++i) {
        cout << data[i] << " ";
    }
    return 0;
}
void MergeSort(int* arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}
void Merge(int* arr, int low, int mid, int high) {
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; ++i) {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}
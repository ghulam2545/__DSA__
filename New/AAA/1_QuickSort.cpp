#include <algorithm>
#include <iostream>
using namespace std;
void QuickSort(int*, int, int);
int Partition(int*, int, int);
int main() {
    int data[] = {43, 89, 66, 12, 54, 67, 22};
    int len = sizeof(data) / sizeof(data[0]);
    cout << "Before sort data are : \n";
    for (int i = 0; i < len; ++i) {
        cout << data[i] << " ";
    }
    QuickSort(data, 0, len - 1);
    cout << "\n\nAfter sort data are : \n";
    for (int i = 0; i < len; ++i) {
        cout << data[i] << " ";
    }
    return 0;
}
void QuickSort(int* arr, int low, int high) {
    if (low < high) {
        int pos = Partition(arr, low, high);
        QuickSort(arr, low, pos - 1);
        QuickSort(arr, pos + 1, high);
    }
}
int Partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int j = low - 1;
    for (int i = low; i < high; ++i) {
        if (arr[i] < pivot) {
            ++j;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[j + 1], arr[high]);
    return j + 1;
}
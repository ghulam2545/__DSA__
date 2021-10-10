// Not working

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
void mergeSort(int* a, int low, int high);
void merge(int* a, int low, int mid, int high);
int main() {
    srand(time(0));
    const int size = 12;
    int a[size];
    for (size_t i = 0; i < size; ++i) {
        a[i] = rand() % 100;
    }
    for (size_t i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
    mergeSort(a, 0, 11);
    for (size_t i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }

    return 0;
}
void mergeSort(int* a, int low, int high) {
    if (high > low) return;
    int mid = low + (high - low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}
void merge(int* a, int low, int mid, int high) {
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < mid; ++i) {
        arr1.push_back(a[i]);
    }
    for (int j = mid; j < high; ++j) {
        arr2.push_back(a[j]);
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            a[k] = arr1[i];
            k += 1;
            i += 1;
        } else {
            a[k] = arr2[j];
            k += 1;
            j += 1;
        }
    }
    while (i < arr1.size()) {
        a[k] = arr1[i];
        k += 1;
        i += 1;
    }
    while (j < arr2.size()) {
        a[k] = arr2[j];
        k += 1;
        j += 1;
    }
}
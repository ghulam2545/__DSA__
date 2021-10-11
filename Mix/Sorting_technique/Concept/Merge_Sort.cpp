#include <cstdint>
#include <ctime>
#include <iostream>
using namespace std;

void MergeSort(int* arr, int low, int high);
void merge(int* arr, int low, int mid, int high);
int main() {
    srand(time(0));
    const int size = 12;
    int arr[size];
    for (size_t i = 0; i < 12; ++i) {
        arr[i] = rand() % 100;
    }
    cout << "unsorted data : \n";
    for (size_t i = 0; i < 12; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n\nsorted data : \n";
    MergeSort(arr, 0, 11);
    for (size_t i = 0; i < 12; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
void MergeSort(int* arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void merge(int* arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[low + i];
    for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
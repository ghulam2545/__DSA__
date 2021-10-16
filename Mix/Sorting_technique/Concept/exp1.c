#include <conio.h>
#include <stdio.h>
int binary_search(int* arr, int size, int key);
int binary_search_recusive(int* arr, int low, int high, int key);
void merge_sort(int* arr, int low, int high);
void merge(int* arr, int low, int mid, int high);
void quick_sort(int* arr, int low, int high);
void quick_sort_2(int* arr, int low, int high);
int partition_1(int* arr, int low, int high);
int partition_2(int* arr, int low, int high);
void swap(int* a, int* b) {
    int tt = *a;
    *a = *b;
    *b = tt;
}

int main() {
    // int num[] = {7, 4, 5, 3, 2, 8, 1, 6, 9, 1};
    // int size = sizeof(num) / sizeof(num[0]);
    // printf("Unsorted data : \n");
    // for (int i = 0; i < size; ++i) {
    //     printf("%d ", num[i]);
    // }
    // printf("\n");
    // quick_sort_2(num, 0, size - 1);
    // printf("Sorted data : \n");
    // for (int i = 0; i < size; ++i) {
    //     printf("%d ", num[i]);
    // }
    // printf("\n");
}
int binary_search(int* arr, int size, int key) {
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int binary_search_recusive(int* arr, int low, int high, int key) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return mid;
    else if (low == high)
        return -1;
    else if (key > arr[mid])
        return binary_search_recusive(arr, mid + 1, high, key);
    else
        return binary_search_recusive(arr, 0, mid - 1, key);
}
void merge_sort(int* arr, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void merge(int* arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; ++i) left[i] = arr[low + i];
    for (int i = 0; i < n2; ++i) right[i] = arr[mid + 1 + i];
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
void quick_sort(int* arr, int low, int high) {
    if (low >= high) return;
    int pos = partition_1(arr, low, high);
    quick_sort(arr, low, pos - 1);
    quick_sort(arr, pos + 1, high);
}
void quick_sort_2(int* arr, int low, int high) {
    if (low >= high) return;
    int pos = partition_2(arr, low, high);
    quick_sort(arr, low, pos);
    quick_sort(arr, pos + 1, high);
}
int partition_1(int* arr, int low, int high) {
    int pivot = high;
    int index = low;
    for (int i = low; i < high; ++i) {
        if (arr[i] <= arr[pivot]) {
            swap(&arr[i], &arr[index]);
            ++index;
        }
    }
    swap(&arr[index], &arr[pivot]);
    return index;
}
int partition_2(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        do {
            ++i;
        } while (arr[i] < pivot);
        do {
            --j;
        } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
}
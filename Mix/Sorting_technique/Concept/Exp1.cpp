#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

template <typename T>
struct Sort {
    int* size;
    T* arr;
    T* key;
    Sort();

    int binary_search(const T* arr, const int& size, const T& key);                           // for iterative binary search
    int binary_search_recusive(const T* arr, const int& low, const int& high, const T& key);  // for recursive binary search

    void merge_sort(T* arr, const int& low, const int& high);  // merge sort
    void merge(T* arr, const int& low, const int& mid, const int& high);

    void quick_sort(T* arr, const int& low, const int& high);
    void quick_sort_2(T* arr, const int& low, const int& high);
    int partition_first(T* arr, const int& low, const int& high);   // (Hoare_partition_scheme)  by considering first element as pivot
    int partition_last(T* arr, const int& low, const int& high);    // (Lomuto_partition_scheme)  by considering last element as pivot
    int partition_random(T* arr, const int& low, const int& high);  // quick sort by considering random element as pivot
    int partition(T* arr, const int& low, const int& high);         //------ (seg fault)
};
int main() {
    srand(time(0));
    Sort<int> aa;
    int a[] = {4, 5, 3, 6, 8, 3, 1, 4, 7};
    int size = sizeof(a) / sizeof(a[0]);
    cout << "un : \n";
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    aa.quick_sort_2(a, 0, size - 1);
    cout << "\nsot : \n";
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    // int ans = aa.binary_search_recusive(a, 0, 6, -9);
    // cout << ans << "\n";
    return 0;
}

template <typename T>
Sort<T>::Sort() {
    size = new int;
    arr = new T[*size];
    key = new T;
}
template <typename T>
int Sort<T>::binary_search(const T* arr, const int& size, const T& key) {
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
template <typename T>
int Sort<T>::binary_search_recusive(const T* arr, const int& low, const int& high, const T& key) {
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
template <typename T>
void Sort<T>::merge_sort(T* arr, const int& low, const int& high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
template <typename T>
void Sort<T>::merge(T* arr, const int& low, const int& mid, const int& high) {
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
template <typename T>
void Sort<T>::quick_sort(T* arr, const int& low, const int& high) {
    if (low >= high) return;
    int pos = partition_last(arr, low, high);
    quick_sort(arr, low, pos - 1);
    quick_sort(arr, pos + 1, high);
}
template <typename T>
void Sort<T>::quick_sort_2(T* arr, const int& low, const int& high) {
    if (low >= high) return;
    int pos = partition_first(arr, low, high);
    quick_sort(arr, low, pos);
    quick_sort(arr, pos + 1, high);
}
template <typename T>
int Sort<T>::partition_first(T* arr, const int& low, const int& high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);
        do {
            --j;
        } while (arr[j] > pivot);
        if (i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}
template <typename T>
int Sort<T>::partition_last(T* arr, const int& low, const int& high) {
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
template <typename T>
int Sort<T>::partition_random(T* arr, const int& low, const int& high) {
    int pIndex = rand() % (low + high);
    int pivot = arr[pIndex];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);
        do {
            --j;
        } while (arr[j] > pivot);
        if (i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}
template <typename T>
int Sort<T>::partition(T* arr, const int& low, const int& high) {
    int pivot = high;
    int index = low;
    for (int i = low; i < high; ++i) {
        if (arr[i] <= arr[pivot]) {
            std::swap(arr[i], arr[index]);
            ++index;
        }
    }
    std::swap(arr[pivot], arr[index]);
    return index;
}
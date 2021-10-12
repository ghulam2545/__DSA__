/**
 * Problem :
 * Basic sorting technique
 *
 */
#include <bits/stdc++.h>
using namespace std;
struct Sort {
   private:
    const int size = 12;
    int* arr;

   public:
    Sort();
    void print();
    void bubble_sort(int* a, const int& size);
    void insertion_sort(int* a, const int& size);
    void selection_sort(int* a, const int& size);
    void set_sort(int* a, const int size);
    void quick_sort(int* start, int* end);
    int* partition(int* start, int* end);
    void merge_sort(int* a, int low, int high);
    void merge(int* a, int low, int mid, int high);
};
int main() {
    Sort ss;

    return 0;
}

Sort::Sort() {
    srand(time(0));
    arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
    cout << "Unosorted data : \n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n\nDoing bubble sort : \n";
    bubble_sort(arr, size);
    print();
    cout << "\n\nDoing selection sort : \n";
    selection_sort(arr, size);
    print();
    cout << "\n\nDoing insertion sort : \n";
    insertion_sort(arr, size);
    print();
    cout << "\n\nDoing set sort : \n";
    set_sort(arr, size);
    print();
    cout << "\n\nDoing quick sort : \n";
    quick_sort(arr, arr + 12);
    print();
    cout << "\n\nDoing merge sort : \n";
    merge_sort(arr, 0, 11);
    print();
    cout << "\n";
}
void Sort::print() {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}
void Sort::bubble_sort(int* a, const int& size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i; j < size; ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}
void Sort::insertion_sort(int* a, const int& size) {
    int key;
    for (int i = 1; i < size; i++) {
        key = a[i];
        while (i > 0 && a[i - 1] > key) {  // for decreasing chage ">" to "<"
            a[i] = a[i - 1];
            i--;
        }
        a[i] = key;
    }
}
void Sort::selection_sort(int* a, const int& size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (a[i] < a[min]) {
                min = i;
            }
        }
        swap(a[i], a[min]);
    }
}
void Sort::set_sort(int* a, const int size) {
    multiset<int> ans;
    for (int i = 0; i < size; ++i) {
        ans.insert(a[i]);
    }
}
void Sort::quick_sort(int* start, int* end) {
    if (start >= end) return;
    int* index = partition(start, end);
    quick_sort(start, index - 1);
    quick_sort(index + 1, end);
}
int* Sort::partition(int* start, int* end) {
    int pivotElement = *end;
    int* pIndex = start;
    for (auto i = start; i <= end - 1; i++) {
        if (*i <= pivotElement) {
            std::swap(*i, *pIndex);
            pIndex++;
        }
    }
    std::swap(*end, *pIndex);
    return pIndex;
}
void Sort::merge_sort(int* a, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void Sort::merge(int* a, int low, int mid, int high) {
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int left[size1];
    int right[size2];
    for (int i = 0; i < size1; ++i) {
        left[i] = a[low + i];
    }
    for (int i = 0; i < size2; ++i) {
        right[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while (i < size1 && j < size2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            ++i;
        } else {
            a[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < size1) {
        a[k] = left[i];
        ++i;
        ++k;
    }
    while (j < size2) {
        a[k] = right[j];
        ++j;
        ++k;
    }
}
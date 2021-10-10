/**
 *
 *
 *
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
    void quick_sort();
    void set_sort(int* a, const int size);
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
void Sort::quick_sort() {}
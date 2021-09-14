#include <bits/stdc++.h>
using namespace std;

void merge_sort(int* arr, int low, int high);
void merge_theme();
int main() {
    int a[] = {2, 7, 5, 9, 2, 1, 4, 6, 8, 3};
    int n = sizeof(a) / sizeof(a[0]);

    return 0;
}
void merge_sort(int* arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge_theme()
}
void merge_theme() {}
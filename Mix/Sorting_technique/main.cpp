#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int size = right - left + 1;
    int i = left;
    int j = mid + 1;
    int k = 0;
    vector<int> sorted(size, 0);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    while (i <= mid) sorted[k++] = arr[i++];
    while (j <= right) sorted[k++] = arr[j++];

    // copying
    for (int i = 0; i < size; ++i) arr[left + i] = sorted[i];
}

void mergesort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {6, 7, 3, 5, 4, 2, 1, 0, 9, 2};
    int n = arr.size();
    mergesort(arr, 0, n - 1);

    for (auto& e : arr) cout << e << ' ';
}
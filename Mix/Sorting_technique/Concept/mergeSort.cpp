#include <algorithm>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class master {
   public:
    int* array(int len);
    ~master() {}

    void mergeSort1(int* arr, int low, int high);
    void mergeSort2(int* arr, int low, int high);

    void merge1(int* arr, int low, int high, int mid);
    void merge2(int* arr, int* tmp, int low, int high, int mid);
    void mergeSortHelper(int* arr, int* tmp, int low, int high);  // actually this help me to pass extra array for store data

    void print(int* arr, int len) {
        for (int i = 0; i < len; ++i) cout << arr[i] << " ";
    }

   private:
    int* data;
    int len;
};

int main() {
    master oo;
    int len = 10;
    auto arr = oo.array(len);
    oo.mergeSort2(arr, 0, len - 1);
    oo.print(arr, len);

    return 0;
}

int* master::array(int len) {
    srand(time(0));
    this->len = len;
    data = new int[len];
    for (int i = 0; i < len; ++i) data[i] = rand() % 100;
    for (int i = 0; i < len; ++i) cout << data[i] << " ";
    cout << "\n";
    return data;
}

void master::mergeSort1(int* arr, int low, int high) {
    int mid = 0;
    if (low < high) {
        mid = low + (high - low) / 2;
        mergeSort1(arr, low, mid);       // first part will be half or half + 1
        mergeSort1(arr, mid + 1, high);  // second part will be half or half - 1
        merge1(arr, low, high, mid);
    }
}

void master::merge1(int* arr, int low, int high, int mid) {
    int x = mid - low + 1;
    int y = high - mid;
    int left[x];
    int right[y];
    for (int i = 0; i < x; ++i) left[i] = arr[low + i];       // each time index will start from low
    for (int i = 0; i < y; ++i) right[i] = arr[mid + 1 + i];  // each time index will start from mid + 1

    int i = 0, j = 0, k = low;
    while (i < x && j < y) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < x) arr[k++] = left[i++];
    while (j < y) arr[k++] = right[j++];
}

void master::mergeSort2(int* arr, int low, int high) {
    int tmp[high - low + 1];
    mergeSortHelper(arr, tmp, low, high);
}

void master::mergeSortHelper(int* arr, int* tmp, int low, int high) {
    int mid = 0;
    if (low < high) {
        mid = low + (high - low) / 2;
        mergeSortHelper(arr, tmp, low, mid);
        mergeSortHelper(arr, tmp, mid + 1, high);
        merge2(arr, tmp, low, high, mid + 1);  // pass mid + 1 coz for second part
    }
}

void master::merge2(int* arr, int* tmp, int low, int high, int mid) {
    int i = low;
    int j = mid;
    int k = low;
    while (i <= mid - 1 && j <= high) {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    while (i <= mid - 1) tmp[k++] = arr[i++];
    while (j <= high) tmp[k++] = arr[j++];
    for (int i = low; i <= high; ++i) arr[i] = tmp[i];  // copying to actual array from temp
}
#include <iostream>
using namespace std;
int f_first(int* arr, int size, int data);
int f_last(int* arr, int size, int data);
int main() {
    int num[] = {10, 20, 20, 20, 30, 30, 40, 50, 50, 50, 60, 70};
    int n = sizeof(num) / sizeof(num[0]);
    int toSearch = 20;
    cout << "first : " << f_first(num, n, toSearch) << "\n\n";
    cout << "last : " << f_last(num, n, toSearch) << "\n\n";

    return 0;
}

int f_first(int* arr, int size, int data) {
    int low = 0;
    int high = size - 1;
    int res = -1;
    int mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (data == arr[mid]) {
            res = mid;
            high = mid - 1;
        } else if (data > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

int f_last(int* arr, int size, int data) {
    int low = 0;
    int high = size - 1;
    int res = -1;
    int mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (data == arr[mid]) {
            res = mid;
            low = mid + 1;
        } else if (data > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

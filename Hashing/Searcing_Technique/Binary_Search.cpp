#include <iostream>
using namespace std;
int f_1(int* arr, int& size, int& data);
int f_2(int* arr, int low, int high, int& data);

int main() {
    int num[] = {23, 33, 37, 50, 66, 67, 99};
    int n = sizeof(num) / sizeof(num[0]);
    int toSearch = 929;
    cout << f_1(num, n, toSearch) << "\n\n";
    int first = 0;
    int last = n - 1;
    cout << f_2(num, first, last, toSearch) << "\n\n";
    return 0;
}

int f_1(int* arr, int& size, int& data) {
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (data == arr[mid]) {
            return mid;
        } else if (data > arr[mid]) {
            low = mid + 1;
        } else if (data < arr[mid]) {
            high = mid - 1;
        }
    }
    return -1;
}

int f_2(int* arr, int low, int high, int& data) {
    int mid = 0;
    while (low <= high) {
    	mid = low + (high - low) / 2; 
        if (data == arr[mid]) {
            return mid;
        } else if (data > arr[mid]) {
            return f_2(arr, mid + 1, high, data);
        } else {
            return f_2(arr, low, high - 1, data);
        }
    }
    return -1;
}

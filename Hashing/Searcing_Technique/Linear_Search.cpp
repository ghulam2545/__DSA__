#include <iostream>
using namespace std;
int f_1(int* arr, int& size, int& data);
int f_2(int* arr, int& size, int& data); // Something like 2 pointer tech..
int f_3(int* arr, int& size, int& data); // Something like 2 pointer tech..
int main() {
    int num[] = {23, 54, 90, 78, 66, 54, 33};
    int n = sizeof(num) / sizeof(num[0]);
    int toSearch = 33;
    cout << f_1(num, n, toSearch) << "\n\n";
    cout << f_2(num, n, toSearch) << "\n\n";
    cout << f_3(num, n, toSearch);

    return 0;
}

int f_1(int* arr, int& size, int& data) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == data) {
            return i;
        }
    }
    return -1;
}

int f_2(int* arr, int& size, int& data) {
    int left = 0;
    int right = size - 1;
    for (int i = left; i <= right;) {
        if (arr[i] == data) {
            return i;
        }
        if (arr[right - i] == data) {
            return right - i;
        }
        left++;
        right--;
    }
    return -1;
}

int f_3(int* arr, int& size, int& data) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        if (data == arr[low]) {
            return low;
        } else if (data == arr[high]) {
            return high;
        }
        ++low;
        --high;
    }
    return -1;
}

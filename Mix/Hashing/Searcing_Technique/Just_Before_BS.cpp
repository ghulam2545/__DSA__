#include <iostream>
using namespace std;
int f_1(int* arr, int& size, int& data);

int main() {
    int num[] = {23, 33, 37, 50, 66, 67, 99};
    int n = sizeof(num) / sizeof(num[0]);
    int toSearch = 36;
    cout << f_1(num, n, toSearch) << "\n\n";

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
    return low;
}

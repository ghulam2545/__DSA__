// Uncompelte...

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> ans(int* arr, int& size, int& data);
int fn(int& key);
int main() {
    pair<int, int> p;
    int num[] = {2, 4, 6, -9, 7, -4, -5, -2, 3, 1};
    int n = sizeof(num) / sizeof(num[0]);
    data = -13;
    p = ans(arr, n, data);

    return 0;
}

int fn(int& key) { return key % 10; }
pair<int, int> ans(int* arr, int& size, int& data) {
    vector<int> v[10];
    for (int i = 0; i < 10; i++) {
        v[fn(arr[i])].push_back(arr[i]);
    }
}
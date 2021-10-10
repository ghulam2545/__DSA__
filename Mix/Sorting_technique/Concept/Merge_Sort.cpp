// #include <bits/stdc++.h>
// using namespace std;
// void partition(int* a, int low, int high);

// int main() {
//     srand(time(0));
//     const int size = 12;
//     int a[size];
//     for (int i = 0; i < size; ++i) {
//         a[i] = rand() % 100;
//     }
//     for (int i = 0; i < size; ++i) {
//         cout << a[i] << " ";
//     }

//     return 0;
// }
// void partition(int* a, int low, int high) {
//     int mid = low + (high - low) / 2;
//     if (high >= low) {
//         return;
//     }
//     if (high & 1) {  // Odd
//         partition(a, low, mid);
//     } else {
//         partition(a, mid + 1, high);
//     }
// }
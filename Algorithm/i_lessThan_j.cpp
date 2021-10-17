// 
// // An interesting problem for TC
// #include <bits/stdc++.h>
// using namespace std;

// // sum equal given x
// void pro_1(int* arr, int sz, int x);

// // arr[i] xor arr[j] == 0
// void pro_2(int* arr, int sz);

// int main() {
//     int arr[] = {1, 0, 3, 5, 3, 6, 6, 4, 2};
//     int arr2[] = {1, 3, 4, 1, 4};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//     pro_1(arr, sz, 6);
//     pro_2(arr2, sz2);
//     return 0;
// }
// void pro_1(int* arr, int sz, int x) {
//     int ans = 0;
//     // sort(arr, arr + sz);
//     int low = 0;
//     int high = sz - 1;
//     while (low < high) {
//         if (arr[low] + arr[high] == x) {
//             ++ans;
//             ++low;
//             --high;
//         } else if (arr[low] + arr[high] > x) {
//             --high;
//         } else {
//             ++low;
//         }
//     }
//     cout << ans << "\n";
// }
// void pro_2(int* arr, int sz) {
//     int ans = 0;
//     sort(arr, arr + sz);
//     int low = 0;
//     int high = sz - 1;
//     while (low < high) {
//         if ((arr[low] ^ arr[high]) == 0) {
//             ++ans;
//             ++low;
//             --high;
//         } else if ((arr[low] ^ arr[high]) > 0) {
//             --high;
//         } else {
//             ++low;
//         }
//     }
//     cout << ans << "\n";
// }
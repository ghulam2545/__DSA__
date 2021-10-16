// counting sort
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define read(n) \
    for (ll i = 0; i < n; ++i) cin >> arr[i];
#define print(n) \
    for (ll i = 0; i < n; ++i) cout << arr[i] << " ";
using namespace std;
void solve();
void counting_sort(int* arr, int size);
int main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
void solve() {
    int arr[] = {1, 3, 4, 5, 2, 3, 6, 7, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(size);
    cout << "\n";
    counting_sort(arr, size);
    cout << "\n";
}
void counting_sort(int* arr, int size) {
    int ans[size];
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    int a[max + 2];
    for (int i = 0; i < max + 2; ++i) a[i] = 0;
    for (int i = 0; i < size; ++i) {
        ++a[arr[i]];
    }
    for (int i = 1; i < max + 2; ++i) {
        a[i] += a[i - 1];
    }
    // for (int i = 0; i < max + 2; ++i) {
    //     cout << a[i] << " ";
    // }
    for (int i = 0; i < size; ++i) {
        --a[arr[i]];
        int index = a[arr[i]];
        ans[index] = arr[i];
    }
    for (int i = 0; i < size; ++i) {
        cout << ans[i] << " ";
    }
}
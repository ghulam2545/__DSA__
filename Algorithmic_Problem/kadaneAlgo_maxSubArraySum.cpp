#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = INT_MIN;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += arr[i];
        if (ans < temp) {
            ans = temp;
        }
        if (temp < 0) {
            temp = 0;
        }
    }
    cout << ans;
    return 0;
}

/*
2 -3 4 -2 3 8 -4 -3 4
ans = 13
*/

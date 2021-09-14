#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n + 1; i++) {
        arr[i] = arr[i] + arr[i - 1];
    }

    vector<int> ans;
    int q;
    cin >> q;
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        ans.push_back(arr[b] - arr[a - 1]);
    }
    for (int& e : ans) cout << e << "\n";
    return 0;
}

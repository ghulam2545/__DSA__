#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int, int>> job;
    int n;
    cin >> n;
    int profit[n], deadline[n];
    for (int i = 0; i < n; ++i) cin >> profit[i];
    for (int i = 0; i < n; ++i) cin >> deadline[i];
    for (int i = 0; i < n; ++i) job.push_back({profit[i], deadline[i]});
    std::sort(job.rbegin(), job.rend());
    int size = 0;
    for (auto e : job) size = std::max(size, e.second);
    int arr[size];
    for (int i = 0; i < size; ++i) arr[i] = -1;
    for (auto e : job) {
        e.second -= 1;
        while (e.second >= 0) {
            if (arr[e.second] == -1) {
                arr[e.second] = e.first;
                break;
            } else {
                --e.second;
            }
        }
    }
    int temp = 0;
    for (auto e : job) temp += e.first;
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != -1) ans += arr[i];
    }
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "total profit : " << ans << "\ntotal penalty : " << temp - ans;

    return 0;
}

/*
7
75 85 55 35 45 70 60
5 2 4 3 2 5 3

7
30 35 20 25 12 15 5
3 4 4 2 3 1 2

9
50 40 60 70 30 20 45 55 35
5 3 2 7 5 4 2 3 4

*/
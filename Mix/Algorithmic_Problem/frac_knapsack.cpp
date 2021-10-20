// No need to use map (improve)
#include <bits/stdc++.h>
using namespace std;
struct item {
    int profit;
    int weight;
};
class solve {
   public:
    double solution(int W, item* arr, int n);
};
int main() {
    int size;
    cin >> size;
    item a[size];
    int pro, wei;
    for (int i = 0; i < size; ++i) {
        cin >> pro;
        a[i].profit = pro;
    }
    for (int i = 0; i < size; ++i) {
        cin >> wei;
        a[i].weight = wei;
    }
    int W;
    cin >> W;
    solve ss;
    printf("%.2lf", ss.solution(W, a, size));

    return 0;
}
double solve::solution(int W, item* arr, int n) {
    unordered_map<int, double> bag;
    for (int i = 0; i < n; ++i) {
        bag[i] = arr[i].profit / (double)arr[i].weight;
    }
    vector<pair<int, double>> v(bag.begin(), bag.end());
    sort(v.rbegin(), v.rend(), [](auto& left, auto& right) { return left.second < right.second; });
    double ans = 0;
    for (auto e : v) {
        if (arr[e.first].weight <= W) {
            ans += arr[e.first].profit;
            W -= arr[e.first].weight;
        } else {
            double xx = (W / (double)arr[e.first].weight) * 100;
            ans += ((double)arr[e.first].profit * xx) / 100;
            break;
        }
    }
    return ans;
}

/*
5
30 20 100 90 160
5 10 20 30 40
60

4
11 21 31 33
2 11 22 15
40

*/
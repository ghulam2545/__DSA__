/**
 * Given an integer array, find the maximum product of its elements
 * among all its subsets. (subseq + contig)
 */

#include <iostream>
#include <vector>
using namespace std;

int product(vector<int> arr) {
    int ans = 1;
    for (auto e : arr) ans *= e;
    return ans;
}

void power_set(vector<int> in, vector<int> out, int& ans) {
    if (in.empty()) {
        ans = max(ans, product(out));
        return;  // don't forget this, otherwise lol
    }
    auto last = in.back();
    in.pop_back();
    power_set(in, out, ans);
    out.push_back(last);
    power_set(in, out, ans);
}

int main() {
    vector<int> a = {-6, 4, -5, 8, -10, 0, 8};
    vector<int> b = {4, -8, 0, 8};
    vector<int> c = {1, 2, 3, 4};

    vector<int> ans;
    int s = 0;
    power_set(a, ans, s);
    cout << s;
    return 0;
}
//  diff index for sum X val

#include <bits/stdc++.h>
using namespace std;
// O(n^2)
bool ans_1(vector<int> input, const int &data) {
    bool ans = false;
    for (int i = 0; i < input.size() - 1; i++) {
        for (int j = i + 1; j < input.size(); j++) {
            if ((input[i] + input[j]) == data) {
                ans = true;
            }
        }
    }
    return ans;
}
// O(nlogn)
bool ans_2(vector<int> input, const int &data) {
    sort(input.begin(), input.end());
    int low = 0;
    int high = input.size() - 1;
    bool ans = false;
    while (low <= high) {
        if ((input[low] + input[high]) == data) {
            ans = true;
        }
        if ((input[low] + input[high]) > data) {
            --high;
        } else {
            ++low;
        }
    }
    return ans;
}
// O(n)
bool ans_3(vector<int> input, const int &data) {
    bool ans = false;
    unordered_set<int> s;
    for (int e : input) {
        int req = data - e;
        if (s.find(req) != s.end()) {
            ans = true;
        } else {
            s.insert(e);
        }
    }
    return ans;
}
// bool search(int *arr, const int &data) {}
int main() {
    cout << "Test...\n";
    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << ans_1(num, 6) << "\n";
    cout << ans_1(num, 20) << "\n";
    cout << ans_2(num, 6) << "\n";
    cout << ans_2(num, 20) << "\n";
    cout << ans_3(num, 6) << "\n";
    cout << ans_3(num, 20) << "\n";
    return 0;
}
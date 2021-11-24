#include <bits/stdc++.h>
using namespace std;

// Navie approch
vector<int> suffixArray(string str);

//

int main() {
    string str = "banana";
    vector<int> ans = suffixArray(str);
    for (int& e : ans) cout << e << " ";

    return 0;
}
vector<int> suffixArray(string str) {
    vector<int> ans;
    vector<pair<string, int>> storage;
    for (int i = 0; i < str.size(); ++i) {
        storage.push_back(make_pair(str.substr(i), i));
    }
    cout << "before : \n";
    for (auto e : storage) {
        cout << e.first << "  " << e.second << "\n";
    }

    sort(storage.begin(), storage.end());

    cout << "after : \n";
    for (auto e : storage) {
        cout << e.first << "  " << e.second << "\n";
    }

    for (auto e : storage) {
        ans.push_back(e.second);
    }
    return ans;
}
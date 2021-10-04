// Voilating DRY

#include <bits/stdc++.h>
using namespace std;
bool helper(const pair<string, int> &a, const pair<string, int> &b) { return (a.second < b.second); }
bool helper2(const pair<string, int> &a, const pair<string, int> &b) { return (a.second < b.second); }
class VectorSort {
    vector<pair<string, int>> v;

   public:
    void insertEle();
    void IncByFirst();
    void IncBySecond();
    void DecByFirst();
    void DecBySecond();
};
class MapSort {
    unordered_map<string, int> h;
    // why it can not be global
    // vector<pair<int, string>> ans;

   public:
    void insertEle();
    void IncByFirst();
    void IncBySecond();
    void DecByFirst();
    void DecBySecond();
};
int main() {
    VectorSort *ob = new VectorSort();
    MapSort *oo = new MapSort();
    // ob->IncByFirst();
    // cout << "\n";
    // ob->IncBySecond();
    // cout << "\n";
    // ob->DecByFirst();
    // cout << "\n";
    // ob->DecBySecond();
    // oo->IncByFirst();
    // cout << "\n";
    // oo->IncBySecond();
    // cout << "\n";
    // oo->DecByFirst();
    // cout << "\n";
    // oo->DecBySecond();

    return 0;
}
void VectorSort::insertEle() {
    v.push_back({"mahboob ", 30});
    v.push_back({"saba", 20});
    v.push_back({"ali", 40});
    v.push_back({"azam", 10});
    v.push_back({"mahboob", 56});
}
void VectorSort::IncByFirst() {
    insertEle();
    sort(v.begin(), v.end());
    for (auto e : v) {
        cout << e.first << " " << e.second << "\n";
    }
}
void VectorSort::IncBySecond() {
    sort(v.begin(), v.end(), helper);
    for (auto e : v) {
        cout << e.first << " " << e.second << "\n";
    }
}
void VectorSort::DecByFirst() {
    sort(v.rbegin(), v.rend());
    for (auto e : v) {
        cout << e.first << " " << e.second << "\n";
    }
}
void VectorSort::DecBySecond() {
    sort(v.rbegin(), v.rend(), helper2);
    for (auto e : v) {
        cout << e.first << " " << e.second << "\n";
    }
}
void MapSort::insertEle() {
    vector<string> names{"noor", "saba", "ali", "noor", "saba", "naseem", "wali"};
    for (int i = 0; i < names.size(); ++i) {
        h[names[i]]++;
        // cout << e << "\n";
    }
}
void MapSort::IncByFirst() {
    insertEle();
    vector<pair<string, int>> ans(h.begin(), h.end());
    sort(ans.begin(), ans.end());
    for (auto e : ans) {
        cout << e.first << " " << e.second << "\n";
    }
}
void MapSort::IncBySecond() {
    vector<pair<string, int>> ans(h.begin(), h.end());
    sort(ans.begin(), ans.end(), helper);
    for (auto e : ans) {
        cout << e.first << " " << e.second << "\n";
    }
}
void MapSort::DecByFirst() {
    vector<pair<string, int>> ans(h.begin(), h.end());
    sort(ans.rbegin(), ans.rend());
    for (auto e : ans) {
        cout << e.first << " " << e.second << "\n";
    }
}
void MapSort::DecBySecond() {
    vector<pair<string, int>> ans(h.begin(), h.end());
    sort(ans.rbegin(), ans.rend(), helper2);
    for (auto e : ans) {
        cout << e.first << " " << e.second << "\n";
    }
}
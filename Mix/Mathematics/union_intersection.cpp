#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define read(n) \
    for (ll i = 0; i < n; ++i) cin >> arr[i];
#define print(n) \
    for (ll i = 0; i < n; ++i) cout << arr[i] << " ";
using namespace std;
void solve();
int main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
void solve() {
    vector<char> a{'a', 'b', 'c', 'd', 'e'};
    vector<char> b{'d', 'e', 'f', 'g'};
    for (char& e : a) cout << e << " ";
    cout << "\n";
    for (char& e : b) cout << e << " ";
    cout << "\n";
    set<char> union_;
    for (char& e : a) union_.insert(e);
    for (char& e : b) union_.insert(e);
    for (char e : union_) cout << e << " ";
    cout << "\n";
    unordered_map<char, char> h;
    vector<char> ans;
    for (char& e : a) {
        if (h.find(e) != h.end()) {
            ans.push_back(e);
        } else {
            h[e] = e;
        }
    }
    for (char& e : b) {
        if (h.find(e) != h.end()) {
            ans.push_back(e);
        } else {
            h[e] = e;
        }
    }
    for (char& e : ans) cout << e << " ";
    cout << "\n";
}
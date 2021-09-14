#include <bits/stdc++.h>
using namespace std;

// both list forward directional and just append   "0"  and   "1"
vector<string> binCode(const int &n) {
    if (n == 0)
        return {"0"};
    if (n == 1)
        return {"0", "1"};
    vector<string> temp = binCode(n - 1);
    vector<string> ans;
    for (int i = 0; i < temp.size(); i++) {
        string s = temp[i];
        ans.push_back("0" + s);
    }
    for (int i = 0; i < temp.size(); i++) {
        string s = temp[i];
        ans.push_back("1" + s);
    }
    return ans;
}
// first list forward directional and second reverse and then append   "0"  and   "1"
vector<string> garyCode(const int &n) {
    if (n == 0)
        return {"0"};
    if (n == 1)
        return {"0", "1"};
    vector<string> temp = garyCode(n - 1);
    vector<string> ans;
    for (int i = 0; i < temp.size(); i++) {
        string s = temp[i];
        ans.push_back("0" + s);
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        string s = temp[i];
        ans.push_back("1" + s);
    }
    return ans;
}

int main() {
    vector<string> ss = binCode(3);
    
    for (auto e : ss)
        cout << e << " ";
    return 0;
}

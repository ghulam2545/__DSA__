#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// Naive approach     O(txt_size * patt_size)
vector<int> solve_1(string txt, string patt);

//

int main() {
    string txt = "AABAACAADAABAABA";
    string patt = "AABA";
    vector<int> ans = solve_1(txt, patt);
    for (int& e : ans) cout << e << " ";
    return 0;
}
vector<int> solve_1(string txt, string patt) {
    int txt_size = txt.size();
    int patt_size = patt.size();
    vector<int> v;
    for (int i = 0; i <= txt_size - patt_size; ++i) {
        int j = 0;
        for (j = 0; j < patt_size; ++j) {
            if (txt[i + j] != patt[j]) {
                break;
            }
        }
        if (j == patt_size) v.push_back(i);
    }
    return v;
}
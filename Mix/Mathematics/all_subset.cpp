// 00000  -- 11111
#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int number = pow(2, sizeof(arr) / sizeof(arr[0]));
    vector<string> v;
    for (int i = 0; i < number; ++i) {
        bitset<5> data = bitset<5>(i);
        v.push_back(data.to_string());
    }
    for (auto e : v) {
        string s = e;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '1') {
                cout << arr[s.size() - 1 - i];
            }
        }
        cout << "\n";
    }

    return 0;
}
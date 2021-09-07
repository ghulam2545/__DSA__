#include <bits/stdc++.h>
using namespace std;

int main() {
    std::set<int> s;
    s.insert(12);
    s.insert(20);
    s.insert(13);
    s.insert(4);
    s.insert(0);
    s.insert(-5);

    for (auto& e : s) {
        cout << e << " ";
    }

    return 0;
}

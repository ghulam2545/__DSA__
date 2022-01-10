// Some issue

/*
Mid school method

first find all factors of both number then filter common number
in both and return their multiplication

*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int gcd(int a, int b);
vector<int> factors(int n);

int main() {
    int aa = 205;
    int bb = 123;
    cout << gcd(aa, bb);

    return 0;
}

int gcd(int a, int b) {
    vector<int> ans1 = factors(a);
    vector<int> ans2 = factors(b);
    /*
    set<int> ss;
    for (auto e : ans1) ss.insert(e);
    for (auto e : ans2) ss.insert(e);
    long long int ans = 1;
    for (auto e : ss) {
        ans *= e;
    }
    */
    return ans;
}

vector<int> factors(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (n / i == i) {
                ans.push_back(i);
            } else {
                ans.push_back(i);
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}
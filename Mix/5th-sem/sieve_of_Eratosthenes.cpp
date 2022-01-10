// An standered approach to genrate prime number

#include <iostream>
#include <vector>
using namespace std;

vector<int> prime(int n);
int main() {
    int nn = 25;
    vector<int> ans = prime(nn);
    for (auto e : ans) cout << e << " ";

    return 0;
}

vector<int> prime(int n) {
    bool isPrime[n + 1];
    for (int i = 0; i <= n; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i] == true) {
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= n; ++i) {
        if (isPrime[i] == true) {
            ans.push_back(i);
        }
    }
    return ans;
}
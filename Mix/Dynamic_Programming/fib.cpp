#include <iostream>
#define ll long long int
#define size 1000
using namespace std;
ll table[size];

ll fib(ll num) {  // just recursive
    if (num <= 1) {
        return num;
    } else {
        return fib(num - 1) + fib(num - 2);
    }
}

// top - down appr.
ll fib_dp(ll num) {  // is like comming high number to zero
    if (table[num] == -1) {
        if (num <= 1) {
            table[num] = num;
        } else {
            table[num] = fib_dp(num - 1) + fib_dp(num - 2);
        }
    }
    return table[num];
}

int main() {
    for (int i = 0; i < size; ++i) {
        table[i] = -1;
    }
    int num = 23;
    cout << fib(num) << "\n" << fib_dp(num);
    return 0;
}
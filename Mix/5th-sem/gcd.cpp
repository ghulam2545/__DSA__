// Euclid algorithm to find gcd of two number

#include <iostream>
using namespace std;

// recursive approach O(n)  --  O(n)
int gcd(int a, int b);

// iterative approach O(n)  --  O(1)
int gcd_(int a, int b);

int main() {
    int aa = 205;
    int bb = 123;
    cout << gcd(aa, bb) << "\n" << gcd_(aa, bb);

    return 0;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd_(int a, int b) {
    if (b == 0) return a;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
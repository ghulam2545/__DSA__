// Consecutive integer checking gcd method
/*
Step 1 : Assign the value of min{m, n} to t.
Step 2 : Divide m by t. If the remainder of this division is 0, go to Step 3;
        otherwise, go to Step 4.
Step 3 : Divide n by t. If the remainder of this division is 0, return the value of
        t as the answer and stop; otherwise, proceed to Step 4.
Step 4 : Decrease the value of t by 1. Go to Step 2.

Note : this will not work for 0 (any one integer as zero)
*/

#include <iostream>
using namespace std;

// O(n)  --  O(1)
int gcd(int a, int b);
int main() {
    cout << gcd(205, 123);

    return 0;
}

int gcd(int a, int b) {
    int tt = min(a, b);
    int ans = 0;
    do {
        if (a % tt == 0) {
            if (b % tt == 0) {
                ans = tt;
                break;
            } else {
                --tt;
            }
        } else {
            --tt;
        }
    } while (true);
    return ans;
}
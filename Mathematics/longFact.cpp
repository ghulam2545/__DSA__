#include <iostream>
#define mod (uint64_t)1000000007
using namespace std;

uint64_t longFact(uint64_t num) {
    uint64_t def = 1;
    for (int i = 1; i <= num; i++) {
        def = (def * i) % mod;
    }
    return def;
}

int main() {
    uint64_t ans = longFact(23);
    cout << ans;
    cout << "\n" << longFact(5);
}
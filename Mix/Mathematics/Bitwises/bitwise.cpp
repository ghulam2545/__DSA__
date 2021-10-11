#include <bitset>
#include <cstdint>
#include <iostream>
#include <typeinfo>
using namespace std;
int main() {
    unsigned a = 0x6db7;
    cout << typeid(a).name() << "\n";
    unsigned ans = a & 0x3f;
    printf("%x\n", ans);

    // uint16_t a = 0x6db7;
    // uint16_t b = 0xa726;
    // printf("%x\n", a & b);
    // printf("%x\n", a | b);
    // printf("%x\n", a ^ b);
    // printf("%x\n", ~a);
    // printf("%x\n", ~b);
    // unsigned num = 0x5b3c;
    // printf("%x\n", num);
    // printf("%x\n", ~num);
    // cout << bitset<16>(num);
    // cout << "\n";

    // cout << num << "\n";
    // cout << (~num) << "\n";

    return 0;
}
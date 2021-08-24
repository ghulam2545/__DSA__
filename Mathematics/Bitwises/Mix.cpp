#include <bits/stdc++.h>
using namespace std;
struct Experiment {
    void Odd_Even();
    void Raise_Unraise_Power();
    void SetBit();
};

int main() {
    Experiment aa;
    // aa.Odd_Even();
    // aa.Raise_Unraise_Power();
    aa.SetBit();
    return EXIT_SUCCESS;
}

void Experiment::Odd_Even() {
    int num1 = 4;

    // Perform bitwise and on right most bit on given number
    if (num1 & 1) {
        cout << "Odd\n";
    } else {
        cout << "Even\n";
    }
}
void Experiment::Raise_Unraise_Power() {
    int num = 5;

    // Shifting one left is equal to multiplying by 2 in given number
    cout << (num << 2) << "\n";
    // Reverse of left shift
    cout << (36 >> 1);

    // FOCUS : in left shift we add 0 rightside so length incerease
    //         in right shift we discard bits from rightside so length decerease
}

void Experiment::SetBit() {
    int num = 9;  // 1001;
    int pos = 2;  // like 1101  (0 based)

    // first left shift with 1 then bitwise OR with actual number;
    // No type to store binary number
    int ans = (num | (1 << pos));
    cout << ans << "\n";
}

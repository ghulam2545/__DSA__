/**
 * first find mask value
 * for mask 0xff  and  0x00ff are same bcz hexadecimal
 * in case left most do ~ op
 *
 */
#include <bitset>
#include <cstdint>
#include <iostream>
using namespace std;
struct masking {
   private:
    uint16_t num;
    uint16_t mask;

   public:
    void extract_6_right_most();
    void extract_6_left_most();
    void transform_8_to_1();
    void transform_8_to_0();
    void reverse_10_right_most();
    void reverse_10_left_most();
};

int main() {
    masking aa;
    aa.extract_6_right_most();
    aa.extract_6_left_most();
    aa.transform_8_to_1();
    aa.transform_8_to_0();
    aa.reverse_10_right_most();
    aa.reverse_10_left_most();

    return 0;
}

void masking::extract_6_right_most() {
    // Extracting right-most 6 bit from num
    num = 0x7bd6;  // 0111 1011 1101 0110
    mask = 0x3f;   // 0000 0000 0011 1111 (problem)
    num &= mask;
    cout << bitset<16>(num) << "\n";
    printf("In hexal : %x\n", num);
    cout << "In decimal : " << num << "\n\n";
}
void masking::extract_6_left_most() {
    // Extracting left - most 6 bit from num
    num = 0x7bd6;  // 0111 1011 1101 0110
    mask = 0x3ff;  // 0000 0011 1111 1111  (~ be here is a meaningful reason)
    num &= ~mask;  // 1111 1100 0000 0000 =  ~mask (problem)
    cout << bitset<16>(num) << "\n";
    printf("In hexal : %x\n", num);
    cout << "In decimal : " << num << "\n\n";
}
void masking::transform_8_to_1() {
    // Transform right-most 8 bit to 1s and remaining original form
    num = 0x3ff4;  // 0011 1111 1111 0100
    mask = 0xff;   // 0000 0000 1111 1111 (problem)
    num |= mask;
    cout << bitset<16>(num) << "\n";
    printf("In hexal : %x\n", num);
    cout << "In decimal : " << num << "\n\n";
}
void masking::transform_8_to_0() {
    // Transform left-most 8 bit to 1s and remaining original form
    num = 0x3ff4;  // 0011 1111 1111 0100
    mask = 0xff;   // 0000 0000 1111 1111
    num |= ~mask;  // 1111 1111 0000 0000
    cout << bitset<16>(num) << "\n";
    printf("In hexal : %x\n", num);
    cout << "In decimal : " << num << "\n\n";
}
void masking::reverse_10_right_most() {
    // reverse right-most 10 bit and remaining original form
    num = 0x3ff4;  // 0011 1111 1111 0100
    mask = 0x3ff;  // 0000 0011 1111 1111 (problem)
    num ^= mask;
    cout << bitset<16>(num) << "\n";
    printf("In hexal : %x\n", num);
    cout << "In decimal : " << num << "\n\n";
}
void masking::reverse_10_left_most() {
    // reverser left-most 10 bit and remaining original form
    num = 0x3ff4;  // 0011 1111 1111 0100
    mask = 0x3f;   // 0000 0000 0011 1111
    num ^= ~mask;  // 1111 1111 1100 0000
    cout << bitset<16>(num) << "\n";
    printf("In hexal : %x\n", num);
    cout << "In decimal : " << num << "\n\n";
}
// This works only for 2 digit number. 
// genralize this for n digit

#include <iostream>
void multiply(int first, int second) {
    int a1 = first / 10;
    int a0 = first % 10;
    int b1 = second / 10;
    int b0 = second % 10;
    int ans = (a1 * b1) * 100 + ((a1 + a0) * (b1 + b0) - (a1 * b1) - (a0 *
    b0)) * 10 + (a0 * b0); std::cout << ans<<"\n";
}

 int main() {
    multiply(22, 33);

    return 0;
}

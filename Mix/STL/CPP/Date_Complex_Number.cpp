#include "Date_Complex_Number.hpp"

#include <iostream>
using namespace std;
using namespace solve;

int main() {
    Complex c{2, 3};
    Complex d{3, 2};
    cout << c << "\n" << d << "\n";
    cout << (c == d) << "\n";
    cout << (c != d) << "\n";
    cout << (c >= d) << "\n";
    return 0;
}

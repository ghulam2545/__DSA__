#include "Date_Complex_Number.hpp"

#include <iostream>
using namespace std;
using namespace solve;

int main() {
    Date d1{11, 11, 11};
    Date d2{12, 12, 12};
    cout << d1 << "\n" << d2 << "\n";
    cout << (d1 == d2);
    return 0;
}

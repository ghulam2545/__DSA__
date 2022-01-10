#include <iostream>

class Superman {
   private:
    int selfPower;
    int equiPower;

   public:
    void Make_Superman(int selfPower, int equiPower);
    Superman operator+(Superman newMan);  // Binary operator overloading -- one parameter
    Superman operator-();                 // Unary operator overloading -- no parameter
    void show();
};
int main() {
    // Superman spiderman;
    // spiderman.Make_Superman(20, 30);
    // Superman antman;
    // antman.Make_Superman(100, 120);

    // Superman mySuperMan;
    // mySuperMan = spiderman + antman;  // FOCUS  ------- + operator, adding non primitive data type.
    // mySuperMan.show();
    // std::cout << "\n\n";

    // Superman negMan;
    // negMan = -antman;
    // negMan.show();
    return EXIT_SUCCESS;
}

void Superman::Make_Superman(int selfPower = 0, int equiPower = 0) {
    this->selfPower = selfPower;
    this->equiPower = equiPower;
}
void Superman::show() {
    std::cout << "selfPower --> " << selfPower << "\n";
    std::cout << "equiPower --> " << equiPower << "\n";
}
Superman Superman::operator+(Superman newMan) {
    Superman temp;
    temp.selfPower = selfPower + newMan.selfPower;
    temp.equiPower = equiPower + newMan.equiPower;
    return temp;
}
Superman Superman::operator-() {
    Superman temp;
    temp.selfPower = -selfPower;
    temp.equiPower = -equiPower;
    return temp;
}

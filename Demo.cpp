#include <iostream>
#include <vector>
void f(std::vector<std::string>& ref) {
    for (std::string& e : ref) std::cout << e << " ";
}

std::vector<std::string>& _f() {
    static std::vector<std::string> v = {"11", "22", "33"};  // always static
    return v;
}

int main() {
    std::vector<std::string> dummy;
    dummy.push_back("one");
    dummy.push_back("two");
    dummy.push_back("three");
    dummy.push_back("four");
    dummy.push_back("five");
    f(dummy);
    std::vector<std::string> number = _f();
    for (std::string& e : number) std::cout << e << " ";

    return 0;
}

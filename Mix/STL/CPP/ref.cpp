#include <iostream>
#include <vector>

void f(std::vector<int> &v);
std::vector<std::string> &f_1();
std::pair<std::vector<std::string>, std::vector<int>> &special(std::vector<int> &v);

int main() {
    std::vector<int> temp = {1, 2, 3, 4, 5};
    f(temp);
    std::vector<std::string> ss = f_1();
    for (std::string &e : ss)
        std::cout << e << " ";
    std::cout << "\n\n";

    std::pair<std::vector<std::string>, std::vector<int>> pp = special(temp);
    ss = pp.first;    // for string
    temp = pp.second; // for int
    for (std::string &e : ss)
        std::cout << e << " ";
    std::cout << "\n\n";
    f(temp);

    return 0;
}
void f(std::vector<int> &v) {
    for (int &e : v)
        std::cout << e << " ";
    std::cout << "\n\n";
}
std::vector<std::string> &f_1() {
    static std::vector<std::string> temp = {"one", "two", "three"}; // gloabal scope
    return temp;
}
std::pair<std::vector<std::string>, std::vector<int>> &special(std::vector<int> &v) {
    static std::vector<std::string> s = {"one", "two", "three"};
    static std::pair<std::vector<std::string>, std::vector<int>> bug = make_pair(s, v);
    return bug;
}

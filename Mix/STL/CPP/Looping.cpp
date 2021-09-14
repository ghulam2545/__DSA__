#include <algorithm>
#include <iostream>
#include <vector>
class print {
   public:
    void operator()(int e) { std::cout << e << " "; }
};

void show(int num) { std::cout << num << " "; }

int main() {
    std::vector<int> v;
    for (int i = 1; i < 11; i++) {
        v.push_back(i);
    }

    std::cout << "Range based loop : ";
    for (int& e : v) std::cout << e << " ";

    std::cout << "\n\nRange based loop : ";
    for (auto it = v.begin(); it != v.end(); it++) std::cout << (*it) << " ";

    std::cout << "\n\nForeach loop : ";
    std::for_each(v.begin(), v.end(), print());  // function obj

    std::cout << "\n\nForeach loop : ";
    std::for_each(v.begin(), v.end(), show);  // function call -- no ()

    std::cout << "\n\nForeach loop : ";
    std::for_each(v.begin(), v.end(), [](int val) { std::cout << val << " "; });  // Using lambda expr

    return EXIT_SUCCESS;
}

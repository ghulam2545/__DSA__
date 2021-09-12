// What is this ???

#include <iostream>
#include <vector>
using namespace std;
class A {
  public:
    A(int) { cout << "A(int)" << endl; }
    A(const A &) { cout << "A(const A&)" << endl; }
    A(const A &&) noexcept { cout << "A(const A&&)" << endl; }
    ~A() { cout << "~S()" << endl; }
};
int main() {
    vector<A> a;
    cout << a.capacity() << endl;
    a.emplace_back(1);
    cout << a.capacity() << endl;
    a.emplace_back(2);
    cout << a.capacity() << endl;
    return 0;
}


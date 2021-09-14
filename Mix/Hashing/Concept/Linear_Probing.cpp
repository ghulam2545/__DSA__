// Uncomplete...

#include <array>
#include <iostream>
using namespace std;
class Hash {
   	public :
    int fn(int& key);
    bool solve(int* arr, int& size, int& data);
};

int main() {
    int num[] = {12, 44, 78, 45, 67, 90, 82, 19, 37, 4, 88, 40};
    int n = sizeof(num) / sizeof(num[0]);
    int toSearch = 67;
    Hash aa;
    cout << aa.solve(num, n, toSearch);

    return 0;
}

int Hash::fn(int& key) {
    return key % 10;
}  // for now I am considering H(k) = k % 10;
bool Hash::solve(int* arr, int& size, int& data) {
    int a[size];
    for(int& e:a) {
        e = -1;
    } 
	int pos;
    for (int i = 0; i < size; i++) {
        pos = Hash::fn(arr[i]);
        if (a[pos] == -1) {
            a[pos] = arr[i];
        } else {
            if(a[pos] ) {

            }
            else {

            }
        }
    }
}

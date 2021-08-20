#include <iostream>
#include <vector>
using namespace std;

class Search {
    public :
	bool Searching_int(int* arr, int size, int toSearch);
    //bool Searching_str(string* arr, int size, int toSearch);
};

int main() {
    int num[] = {12, 34, 56, 43, 54, 90, 34, 78, 44, 20};
    string s[] = {"noman", "shakeel", "saba", "rabi", "omain"};
    int n = sizeof(num) / sizeof(num[0]);
    int m = sizeof(s) / sizeof(s[0]);
    Search a;
    cout<<a.Searching_int(num, n, 433);

    return 0;
}

bool Search::Searching_int(int* arr, int size, int toSearch) { 
    vector<int> ls[10];
    for (int i = 0; i < size; i++) {
        ls[arr[i] % 10].push_back(arr[i]);
    }

    int temp = toSearch % 10;
    bool ans = false;
    for (int& e:ls[temp]) {
		if (e == toSearch) {
            ans = true;
        }
    }
    return ans;
}

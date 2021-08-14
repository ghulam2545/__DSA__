#include <bits/stdc++.h>
using namespace std;
struct Search {
    void search();
};
int main() {
    Search aa;
    aa.search();
    return 0;
}

void Search::search() {
    int n;
    cin >> n;
    list<int> v[10];
    int _input = 0;
    int rem = 0;
    for (int i = 0; i < n; i++) {
        cin >> _input;
        rem = _input % 10;
        v[rem].push_back(_input);
    }
    int data; cin>>data;
	rem = data % 10;
	bool ans = false;
	for (int& e:v[rem]) {
		if(data == e) ans = true; 
	} 
	ans == true ? cout<<"YES\n" : cout<<"NO\n"; 
}

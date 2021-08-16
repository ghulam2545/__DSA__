#include <bits/stdc++.h>
using namespace std;
void f(int* a, int* b) {
	cout << *a << "   " << *b; 
	cout<<"\n\n";
	for(auto i=a; i<=b; i++) {
		cout<<*i<<" ";
	}
	
}
int main() {
    int num[] = {20, 35, 33, 6, 33};
    int* start = num;
    int* end = &num[4];
    f(start, end);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct Pro {
    int data;
    void pro1();  // O(n)
    void pro2();  // O(sqrt(n))
    void pro3();  // O(sqrt(n))
};
int main() {
	Pro a;
	a.pro1();
	a.pro2();
	a.pro3();

    return 0;
}

void Pro::pro1() {
    cin>>data;
    for(int i=1; i<=data; i++) {
        if(data % i == 0) {
            cout<<i<<" ";
        }
    }
}
void Pro::pro2() {
    cout<<"\n\n";
    for(int i=1; i*i<=data; i++) {
        if(data % i == 0) {
            if(data / i == i) cout<<i<<" ";
            else {
                cout<<i<<" "<<data/i<<" ";
            }
        }
    }
}
void Pro::pro3() {
    cout<<"\n\n";
	for(int i=1; i*i<=(data); i++) {
		if(data % i == 0) {
			cout<<i<<" ";
		}
    }
    for(int i=sqrt(data); i>=1; i--) {
    	if(data % i == 0) {
    		if(data / i != i)
    			cout<<data / i<<" ";
		}
	}
}

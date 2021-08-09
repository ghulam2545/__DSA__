#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	const int n = 100;
	for(int i=1; i<=sqrt(n); i++) {
		if(n%i==0) {
			if(n/i==i) {
				cout<<i<<" ";
			}
			else {
				cout<<i<<" "<<n/i<<" ";
			}
		}
	} 
	
	
	return 0;	
}

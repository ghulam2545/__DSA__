#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	const int n = 100;
	for(int i=1; i*i<n; i++) {
		if(n % i == 0)
			cout<<i<<" ";
	} 
	for(int i=sqrt(n); i>=1; i--) {
		if(n % i == 0) {
			cout<<n/i<<" ";
		}
	}
	
	
	return 0;	
}

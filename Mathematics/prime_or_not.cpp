#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	bool prime = true;
	int num; cin>>num;
	for(int i=2; i<=sqrt(num); i++) {
		if(num % i == 0) {
			prime = false;
		}
	}
	prime == true ? cout<<"Prime Number" : cout<<"Not A Prime Number"; 
	
	return 0;	
}

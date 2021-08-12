// 3, 4, 9, 16, 27, 64, 81, 256, 243, 1024, 729, .... 69term

#include <bits/stdc++.h>  
#define ll long long
using namespace std;  
int main() {
	int t = 1; cin>>t;
	while(t--) {
		int n; cin>>n;
		int num = 0;
		ll ans = 1;
		if(n == 1) {
			cout<<3<<"\n";
		}
		else if(n == 2) {
			cout<<4<<"\n";
		}
		else {
			if(n & 1 ) {
				num = ceil(n/2.0);
				while(num--) {
					ans *= 3;
				}
			}
			else {
				num = n / 2;
				while(num--) {
					ans *= 4;
				}
			}
			cout<<ans<<"\n";
		}
	}
	



    return 0;  
}

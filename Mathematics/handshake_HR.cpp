// n person has to shake their hand to each indivisoul, no repitition.

#include <iostream>

int main() {
	int n; std::cin>>n;
	int ans = 0;
	if(n == 1) std::cout<<0<<"\n";
	else {
		for(int i=n-1; i>=1; i--) {
			ans += i;
		}
		std::cout<<ans<<"\n";
	}
	
}

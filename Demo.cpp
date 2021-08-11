#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int t=1; cin>>t;
    while(t--) {
    	unordered_map<int,int> m;
    	vector<int> v;
		int n,k; cin>>n>>k;
    	long long arr[n];
    	for(int i=0; i<n; i++) {
    		cin>>arr[i];
		}
		for(int i=0; i<n; i++) {
			m[arr[i]]++;
		}
		
		for(auto it=m.begin(); it!=m.end(); it++) {
			if((*it).second > k) {
				v.push_back((*it).first);
			}
		}
		if(v.size()) {
			sort(v.begin(), v.end());
			for(int& e:v) cout<<e<<" ";	
		}
		else {
			cout<<-1;
		}
		cout<<"\n";
		
	}
	return 0;
}

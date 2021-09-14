#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int, int>> p[5];
    int a,b;
	for(int i=0; i<5; i++) {
		cin>>a>>b;
    	p[i].push_back(make_pair(a,b));
	}
	
	p[2].push_back({11,22});
	p[4].push_back({33,44});
	
	for(int i=0; i<5; i++) {
		cout<<"pair : "<<i<< " --> ";
		for(auto it=p[i].begin(); it!=p[i].end(); it++) {
			cout<<(*it).first<<" "<<(*it).second<<"  |  ";
		}
		cout<<"\n";
	}
    return 0;
}

/*

10 20 30 40 50 60 70 80 90 99

*/

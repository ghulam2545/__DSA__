#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> m;
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    for(int i=0; i<n; i++) {
        m[arr[i]]++;
    }
    unordered_map<int,int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++) {
        cout<<(*it).first<<"  "<<(*it).second<<"\n";
    }
    return 0;
}

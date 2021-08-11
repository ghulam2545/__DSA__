#include <bits/stdc++.h>  
using namespace std;  
int main() { 
	double temp = 0;
	double _max = 0;
	double _min = 0;
	int n,k; cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	for(int i=0; i<k; i++) {
		_max += arr[i];
		_min = _max; 
	}
	for(int i=k; i<n; i++) {
		temp =	_max + arr[i] - arr[i-k];
		_max = max(_max, temp);
		_min = min(_min, temp);
		
	}
	cout<<_max/k - _min/k;



    return 0;  
}

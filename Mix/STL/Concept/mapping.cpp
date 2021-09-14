#include <bits/stdc++.h>
using namespace std;
int mapping(char& data);
int main() {
	char data = 'F';
	cout<<mapping(data);
	
	return 0;
}
int mapping(char& data) {
	map<char,int> m;
	for(char i='A'; i<='Z'; i++) {
		m[i] = (int)i - 65;
	}
	return m[data];
}

#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; cin>>s;
	char arr[] = {'h','e','l','l','o'};
	int index = 0;
	int _index = 0;
	int size = s.size();
	char _char = arr[index];
	while(index <= 4 && _index <= size) {
		if(_char == s[_index]) {
			arr[index] = 'a';
			_char = arr[++index];
		}
		_index++;
	}
	if(arr[0] == 'a' && arr[1] == 'a' && arr[2] == 'a' && arr[3] == 'a' && arr[4] == 'a') {
		cout<<"YES";	
	}
	else {
		cout<<"NO";
	}
	
	
    return 0;
}

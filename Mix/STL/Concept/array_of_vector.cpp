#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &p) {
	for(int i=0; i<p.size(); i++) {
		cout<<p[i]<<" ";
	}
}
int main() {
    int n;
    cin >> n;
    vector<int> v[n];
    for (int i = 0; i < n; i++) {
        int nn;
        cin >> nn;
        for (int j = 0; j < nn; j++) {
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }
    for (int i = 0; i < n; i++) {
    	print(v[i]);
        cout << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int num = 100000;
    int n; cin>>n;
    bool arr[num+1];
    for(int i=0; i<=num; i++) {
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;

    for(int i=2; i*i<=num; i++) {
        if(arr[i] == true) {
            for(int j=2*i; j<=num; j+=i) {
                arr[j] = false;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<=num; i++) {
        if(arr[i] == true) {
            cout<<i<<" ";
            cnt++;
            if(cnt == n) {
            	break;
			}
        }
    }

    return 0;
}

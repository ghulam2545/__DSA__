#include <iostream>
using namespace std;
int main() {
    int num[] = {-1, 1, -2, 3, 1, -3, -2};
    int n = sizeof(num) / sizeof(num[0]);
    int ans = INT32_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += num[j];
            ans = max(ans, sum);
        }
    }
    cout << ans << " ";
    return 0;
}

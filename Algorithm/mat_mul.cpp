/** Problem :
 * multiplication of n * n square matrix
 *
 */
#include <bits/stdc++.h>
#define max 100
int ans[max][max];
constexpr void multiply(const int (*a)[3], const int (*b)[3], const int& r, const int& c);
using namespace std;
int main() {
    const int row = 3;
    const int col = 3;
    int a[][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    int b[][3] = {{2, 1, 1}, {2, 1, 1}, {2, 1, 1}};
    multiply(a, b, row, col);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
constexpr void multiply(const int (*a)[3], const int (*b)[3], const int& r, const int& c) {
    ans[r][c];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            ans[i][j] = 0;
            for (int k = 0; k < r; ++k) {
                ans[i][j] = a[i][k] * b[k][j];
            }
        }
    }
}
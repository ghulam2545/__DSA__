// ans_3 is not working has to fix

#include <bits/stdc++.h>
using namespace std;

string str1 = "ABCDGH";
string str2 = "AEDFHR";
// int x = str1.size();
// int y = str2.size();
int arr[6][6];
int x = 6;
int y = 6;
// quite slow due to recursion O(2^n)
int ans_1(string s1, string s2, int x, int y);

// tabulation O(|s1| * |s2|)
int ans_2(string s1, string s2, int x, int y);

// memoization
int ans_3(string s1, string s2, int x, int y);
int main() {
    cout << ans_1(str1, str2, x, y);
    cout << "\n";
    cout << ans_2(str1, str2, x, y);
    cout << "\n";
    cout << ans_3(str1, str2, x, y);
    return 0;
}
int ans_1(string s1, string s2, int x, int y) {
    if (x == 0 || y == 0) {
        return 0;
    }
    if (s1[x - 1] == s2[y - 1]) {
        return 1 + ans_1(s1, s2, x - 1, y - 1);
    } else {
        return max(ans_1(s1, s2, x, y - 1), ans_1(s1, s2, x - 1, y));
    }
}
int ans_3(string s1, string s2, int x, int y) {
    if (x == 0 || y == 0)
        return 0;
    else if (s1[x - 1] == s2[y - 1]) {
        if (arr[x - 1][y - 1] == -1) {
            int temp = ans_3(s1, s2, x - 1, y - 1);
            arr[x - 1][y - 1] = 1 + temp;
            return arr[x - 1][y - 1];
        } else {
            return arr[x - 1][y - 1];
        }
    } else {
        int t1 = 0;
        int t2 = 0;
        if (arr[x][y - 1] == -1) {
            int temp = ans_3(s1, s2, x, y - 1);
            arr[x][y - 1] = temp;
            t1 = temp;
        } else {
            t1 = arr[x][y - 1];
        }
        if (arr[x - 1][y] == -1) {
            int temp = ans_3(s1, s2, x - 1, y);
            arr[x - 1][y] = temp;
            t2 = temp;
        } else {
            t2 = arr[x - 1][y];
        }
        return max(t1, 2);
    }
}
int ans_2(string s1, string s2, int x, int y) {
    int _arr[x + 1][y + 1];
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            if (i == 0 || j == 0) {
                _arr[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                _arr[i][j] = 1 + _arr[i - 1][j - 1];
            } else {
                _arr[i][j] = max(_arr[i][j - 1], _arr[i - 1][j]);
            }
        }
    }
    return _arr[x][y];
}
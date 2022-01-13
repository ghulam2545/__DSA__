#include <algorithm>
#include <iostream>
using namespace std;
struct item {
    int weight;
    int profit;
};
int main() {
    // Collecting input data from user
    int n;
    cin >> n;
    int weight[n];
    int profit[n];
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> profit[i];
    }
    int capacity;
    cin >> capacity;
    // Arranging and sorting item by using selection sort
    item arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i].weight = weight[i];
        arr[i].profit = profit[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int minWeight = arr[i].weight;
        int index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].weight < minWeight) {
                minWeight = arr[j].weight;
                index = j;
            }
        }
        std::swap(arr[i], arr[index]);
    }
    // Actual algorithm or building dp table
    int dp[n + 1][capacity + 1];
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < capacity + 1; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                if (j < arr[i - 1].weight) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    int curr = arr[i - 1].profit + dp[i - 1][j - arr[i - 1].weight];
                    dp[i][j] = max(curr, dp[i - 1][j]);
                }
            }
        }
    }
    /*   Dp table
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < capacity + 1; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << "\nMax profit : ";
    cout << dp[n][capacity];
    return 0;
}

/*
4
3 4 6 5
2 3 1 4
8


3
10 20 30
60 100 120
50

5
5 10 20 30 40
30 20 100 90 160
60

*/
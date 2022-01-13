#include <iostream>
using namespace std;
class master {
   public:
    bool** create(const int& n, const int& sum);
    bool isSubset(bool** matt, int* arr, const int& n, const int& sum);
    // Bad thing is that I am not releasing memory (Will do it later)
    ~master();

   private:
    bool** matrix;
};
int main() {
    int n;
    cin >> n;
    int inputArr[n];
    for (int i = 0; i < n; ++i) {
        cin >> inputArr[i];
    }
    int sum = 0;
    cin >> sum;

    master* oo = new master();
    bool** matt = oo->create(n, sum);
    if (oo->isSubset(matt, inputArr, n, sum))
        cout << "YES -- There is a Subset with given sum.\n";
    else
        cout << "NO -- There is no Subset with given sum.\n";

    return 0;
}

bool** master::create(const int& n, const int& sum) {
    matrix = new bool*[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        matrix[i] = new bool[sum + 1];
    }
    for (int i = 0; i <= n; i++) matrix[i][0] = true;
    for (int i = 1; i <= sum; i++) matrix[0][i] = false;
    return matrix;
}
bool master::isSubset(bool** matt, int* arr, const int& n, const int& sum) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1]) matt[i][j] = matt[i - 1][j];
            if (j >= arr[i - 1]) matt[i][j] = matt[i - 1][j] || matt[i - 1][j - arr[i - 1]];
        }
    }
    return matt[n][sum];
}

/*
6
3 34 4 12 11 3
9
*/
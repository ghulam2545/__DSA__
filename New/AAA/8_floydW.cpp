#include <iomanip>
#include <iostream>
#define inf 99
using namespace std;
class master {
   public:
    int** create(const int& n, const int& m);
    int** addEdge(int** gg, const int& src, const int& des, const int& wt);
    void print(int** gg);
    int** FloydWarshall(int** gg);
    ~master();
   private:
    int vv;
    int ee;
    int** matrix;
    int** ans;
};
int main() {
    int n, m;
    cin >> n >> m;
    master* oo = new master();
    int** myG = oo->create(n, m);
    int p, q, r;
    while (m--) {
        cin >> p >> q >> r;
        myG = oo->addEdge(myG, p, q, r);
    }
    // oo->print(myG);
    int** ans = oo->FloydWarshall(myG);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(2);
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int** master::create(const int& n, const int& m) {
    vv = n;
    ee = m;
    matrix = new int*[vv];
    for (int i = 0; i < vv; ++i) {
        matrix[i] = new int[vv];
    }
    for (int i = 0; i < vv; ++i) {
        for (int j = 0; j < vv; ++j) {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = inf;
        }
    }
    ans = new int*[vv];
    for (int i = 0; i < vv; ++i) {
        ans[i] = new int[vv];
    }
    return matrix;
}
int** master::addEdge(int** gg, const int& src, const int& des, const int& wt) {
    gg[src][des] = wt;
    return gg;
}
void master::print(int** gg) {
    for (int i = 0; i < vv; ++i) {
        for (int j = 0; j < vv; ++j) {
            cout << gg[i][j] << " ";
        }
        cout << "\n";
    }
}
int** master::FloydWarshall(int** gg) {
    for (int i = 0; i < vv; ++i) {
        for (int j = 0; j < vv; ++j) ans[i][j] = gg[i][j];
    }
    for (int k = 0; k < vv; ++k) {
        for (int i = 0; i < vv; ++i) {
            for (int j = 0; j < vv; ++j) {
                if (ans[i][j] > (ans[i][k] + ans[k][j]) && ans[i][k] != inf && ans[k][j] != inf) {
                    ans[i][j] = (ans[i][k] + ans[k][j]);
                }
            }
        }
    }
    return ans;
}

/*
4
4
0 3 10
0 1 5
1 2 3
2 3 1
*/
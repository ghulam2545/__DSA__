// little messed up, has to clean
// but working fine

#include <iostream>
#include <utility>
#include <vector>
using namespace std;
// class adjMatrix {
//    public:
//     int** create(int n, int m);
//     void addEdge(int** g, int src, int des, int wt);
//     void print(int** g);
//     int** transpose(int** g);
//     ~adjMatrix();

//    private:
//     int vertex;
//     int edge;
//     int** arr;
// };
class adjList {
   public:
    vector<pair<int, int>>* create(int n, int m);
    void addEdge(vector<pair<int, int>>* input, int src, int des, int wt);
    void print(vector<pair<int, int>>* input);
    vector<pair<int, int>>* transpose(vector<pair<int, int>>* input);
    ~adjList();

   private:
    int vertex;
    int edge;
    vector<pair<int, int>>* v;
};
int main() {
    // int a, b;
    // cin >> a >> b;
    // adjMatrix* oo = new adjMatrix();
    // int** gr = oo->create(a, b);
    // int p, q, r;
    // for (int i = 0; i < b; ++i) {
    //     cin >> p >> q >> r;
    //     oo->addEdge(gr, p, q, r);
    // }
    // oo->print(gr);
    // cout << "\n\n";
    // oo->print(oo->transpose(gr));

    adjList* oo = new adjList();
    int a, b;
    cin >> a >> b;
    vector<pair<int, int>>* gr;
    gr = oo->create(a, b);
    int p, q, r;
    for (int i = 0; i < b; ++i) {
        cin >> p >> q >> r;
        oo->addEdge(gr, p, q, r);
    }
    oo->print(gr);
    cout << "\n";
    oo->print(oo->transpose(gr));
    return 0;
}
// int** adjMatrix::create(int n, int m) {
//     vertex = n;
//     edge = m;
//     arr = new int*[vertex];
//     for (int i = 0; i < vertex; ++i) {
//         arr[i] = new int[vertex];
//     }
//     for (int i = 0; i < vertex; ++i) {
//         for (int j = 0; j < vertex; ++j) {
//             arr[i][j] = 0;
//         }
//     }
//     return arr;
// }
// void adjMatrix::addEdge(int** g, int src, int des, int wt) {
//     //
//     g[src][des] = wt;
// }
// void adjMatrix::print(int** g) {
//     for (int i = 0; i < vertex; ++i) {
//         for (int j = 0; j < vertex; ++j) {
//             cout << g[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }
// int** adjMatrix::transpose(int** g) {
//     int** tmat;
//     tmat = create(vertex, vertex);
//     for (int i = 0; i < vertex; ++i) {
//         for (int j = 0; j < vertex; ++j) {
//             tmat[i][j] = g[j][i];
//         }
//     }
//     return tmat;
// }
// adjMatrix::~adjMatrix() {
//     for (int i = 0; i < vertex; ++i) {
//         delete[] arr[i];
//     }
//     delete[] arr;
// }
vector<pair<int, int>>* adjList::create(int n, int m) {
    vertex = n;
    edge = m;
    v = new vector<pair<int, int>>[vertex];
    return v;
}
void adjList::addEdge(vector<pair<int, int>>* input, int src, int des, int wt) {
    //
    input[src].push_back(make_pair(des, wt));
}
void adjList::print(vector<pair<int, int>>* input) {
    for (int i = 0; i < vertex; ++i) {
        cout << i << "--> ";
        for (auto e : input[i]) {
            cout << e.first << " | " << e.second << "  ";
        }
        cout << "\n";
    }
}
vector<pair<int, int>>* adjList::transpose(vector<pair<int, int>>* input) {
    vector<pair<int, int>>* tlist;
    tlist = create(vertex, edge);
    for (int i = 0; i < vertex; ++i) {
        for (auto e : input[i]) {
            addEdge(tlist, e.first, i, e.second);
        }
    }
    return tlist;
}
adjList::~adjList() { delete[] v; }

/*
6
7
0 1 20
2 1 40
2 3 50
3 4 70
0 4 30
5 0 10
5 3 60
*/
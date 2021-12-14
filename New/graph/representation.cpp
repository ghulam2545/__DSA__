#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
class adjMatrix {
   public:
    int** create(const int& n, const int& m);
    void fill(int** data);
    void print(int** mat);

   private:
    int vertex;
    int edges;
    int** mat;
};

class adjList {
   public:
    vector<pair<int, int>>* create(const int& n, const int& m);
    vector<pair<int, int>>* addEdge(const int& src, const int& des, const int& weight);
    void print(vector<pair<int, int>>* gg);

   private:
    int vertex;
    int edges;
    vector<pair<int, int>>* lst;
};

class edgeList {
   public:
    void create(const int& a, const int& b);
    void addEdges(const int& src, const int& des, const& weight);
    void print();

   private:
    int vertex;
    int edges;
    vector<tuple<int, int, int>>* elst;
};

int main() {
    cout << "start  >> \n";

    /*    adjMatrix ----
    int n, m;
    cin >> n >> m;
    int** val;
    val = new int*[n];
    for (int i = 0; i < n; ++i) {
        val[i] = new int[n];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) val[i][j] = 0;
    int p, q, w;
    for (int i = 0; i < m; ++i) {
        cin >> p >> q >> w;
        val[p][q] = w;
        val[q][p] = w;
    }
    adjMatrix* aa = new adjMatrix();
    int** mainMat = aa->create(n, m);
    aa->fill(val);
    aa->print(val);
    */

    /*  adjList -----
     int n, m;
     cin >> n >> m;
     adjList* bb = new adjList();
     vector<pair<int, int>>* maingg = bb->create(n, m);
     int p, q, w;
     while (m--) {
         cin >> p >> q >> w;
         maingg = bb->addEdge(p, q, w);
     }
     bb->print(maingg);

     */

    /*  edgeList
    edgeList* cc = new edgeList();
    int n, m;
    cin >> n >> m;
    cc->create(n, m);
    int p, q, w;
    while (m--) {
        cin >> p >> q >> w;
        cc->addEdges(p, q, w);
    }
    cc->print();
    */

    cout << "\nend  >> \n";
    return 0;
}

int** adjMatrix::create(const int& n, const int& m) {
    vertex = n;
    edges = m;
    mat = new int*[vertex];
    for (int i = 0; i < vertex; ++i) {
        mat[i] = new int[vertex];
    }
    return mat;
}
void adjMatrix::fill(int** data) {
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            mat[i][j] = data[i][j];
        }
    }
}

void adjMatrix::print(int** mat) {
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<pair<int, int>>* adjList::create(const int& n, const int& m) {
    vertex = n;
    edges = m;
    lst = new vector<pair<int, int>>[vertex];
    return lst;
}
vector<pair<int, int>>* adjList::addEdge(const int& src, const int& des, const int& weight) {
    lst[src].push_back(make_pair(des, weight));
    lst[des].push_back(make_pair(src, weight));
}

void adjList::print(vector<pair<int, int>>* gg) {
    for (int i = 0; i < vertex; ++i) {
        cout << i << "--> ";
        for (auto e : lst[i]) {
            cout << e.first << "  " << e.second << "   ";
        }
        cout << "\n";
    }
}

void edgeList::create(const int& a, const int& b) {
    vertex = a;
    edges = b;
    elst = new vector<tuple<int, int, int>>;
}

void edgeList::addEdges(const int& src, const int& des, const int& weight) {
    tuple<int, int, int> tt = make_tuple(src, des, weight);
    elst->push_back(tt);
}

void edgeList::print() {
    for (int i = 0; i < vertex; ++i) {
        tuple<int, int, int> pp = elst->at(i);
        cout << get<0>(pp) << " " << get<1>(pp) << " " << get<2>(pp) << "\n";
    }
}
/*
6
7
0 1 10
0 3 20
1 5 80
1 2 30
2 3 40
3 4 50
4 5 90

*/
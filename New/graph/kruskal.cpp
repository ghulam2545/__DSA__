// mst for kruskal

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
class master {
   public:
    vector<pair<int, int>>* create(const int& n, const int& m);
    vector<pair<int, int>>* addEdge(const int& src, const int& des, const int& weight);
    void print(vector<pair<int, int>>* out);
    vector<pair<int, int>>* kruskal(vector<pair<int, int>>* gg);

   private:
    int vertex;
    int edges;
    vector<pair<int, int>>* ls;
    int* dist;
};
int main() {
    cout << "start -- \n";
    int n, m;
    cin >> n >> m;
    master* oo = new master();
    vector<pair<int, int>>* myG = oo->create(n, m);
    int p, q, w;
    while (m--) {
        cin >> p >> q >> w;
        myG = oo->addEdge(p, q, w);
    }
    oo->print(myG);
    cout << "\nend";
    return 0;
}

vector<pair<int, int>>* master::create(const int& n, const int& m) {
    vertex = n;
    edges = m;
    ls = new vector<pair<int, int>>[vertex];
    dist = new int[vertex];
    for (int i = 0; i < vertex; ++i) {
        dist[i] = INT32_MAX;
    }
    return ls;
}

vector<pair<int, int>>* master::addEdge(const int& src, const int& des, const int& weight) {
    ls[src].push_back(make_pair(des, weight));
    ls[des].push_back(make_pair(src, weight));
    return ls;
}

void master::print(vector<pair<int, int>>* out) {
    for (int i = 0; i < vertex; ++i) {
        cout << i << "--> ";
        for (auto e : ls[i]) {
            cout << e.first << " " << e.second << "   ";
        }
        cout << "\n";
    }
}
vector<pair<int, int>>* master::kruskal(vector<pair<int, int>>* gg) {
    // wait
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
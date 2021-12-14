#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
class graph {
   public:
    graph();
    vector<pair<int, int>>* create(const int& n, const int& m);
    vector<pair<int, int>>* addEdge(const int& src, const int& des, const int& weight);
    void print(vector<pair<int, int>>* gg);
    void dfs_rec(vector<pair<int, int>>* gg, const int& start);
    void dfs(vector<pair<int, int>>* gg, const int& start);
    void bfs(vector<pair<int, int>>* gg, const int& start);

   private:
    int vertex;
    int edges;
    vector<pair<int, int>>* lst;
    bool* visited;
};

int main() {
    cout << "start-- \n";
    int n, m;
    cin >> n >> m;
    int p, q, w;
    graph* oo = new graph();
    vector<pair<int, int>>* maingg = oo->create(n, m);
    while (m--) {
        cin >> p >> q >> w;
        maingg = oo->addEdge(p, q, w);
    }
    oo->print(maingg);
    cout << "\n\n";
    oo->dfs_rec(maingg, 3);

    cout << "\nend";

    return 0;
}
graph::graph() {
    visited = new bool[vertex];
    for (int i = 0; i < vertex; ++i) {
        visited[i] = false;
    }
}
vector<pair<int, int>>* graph::create(const int& n, const int& m) {
    vertex = n;
    edges = m;
    lst = new vector<pair<int, int>>[vertex];
    return lst;
}
vector<pair<int, int>>* graph::addEdge(const int& src, const int& des, const int& weight) {
    lst[src].push_back(make_pair(des, weight));
    lst[des].push_back(make_pair(src, weight));
    return lst;
}
void graph::print(vector<pair<int, int>>* gg) {
    for (int i = 0; i < vertex; ++i) {
        cout << i << "--> ";
        for (auto e : gg[i]) {
            cout << e.first << " " << e.second << "   ";
        }
        cout << "\n";
    }
}
void graph::dfs_rec(vector<pair<int, int>>* gg, const int& start) {
    for (auto e : gg[start]) {
        if (visited[e.first] == false) {
            cout << e.first << "  ";
            visited[e.first] = true;
            dfs_rec(gg, e.first);
        }
    }
}

void graph::dfs(vector<pair<int, int>>* gg, const int& start) {
    // TODO :
    queue<int> qq;
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
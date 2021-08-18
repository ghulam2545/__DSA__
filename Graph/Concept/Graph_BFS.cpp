#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Graph {
    int _v, _e;
    int u, v;
    vector<int>* ls;
    bool* visit;
    Graph();
    void Print();
    void BFS(int root);
};
int main() {
    Graph aa;
    aa.Print();

    return 0;
}
Graph::Graph() {
    cin >> _v >> _e;
    ls = new vector<int>[_v];
    for (int i = 0; i < _e; i++) {
        cin >> u >> v;
        ls[u].push_back(v);
        ls[v].push_back(u);
    }
    visit = new bool[_e];
    for (int i = 0; i < _e; i++) {
        visit[i] = false;
    }
}
void Graph::Print() {
    for (int i = 0; i < _v; i++) {
        cout << i << "----> ";
        for (int& e : ls[i]) cout << e << " ";
        cout << "\n";
    }
    cout << "\n\n\n\n";
}

// unc...
void Graph::BFS(int root) {
    queue<int> qq;
    qq.push(root);
    while(!qq.empty) {
        int data = qq.front();
        data = 

    }


}

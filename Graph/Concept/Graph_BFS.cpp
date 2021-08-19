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
    void BFS(int nodeValue);
};
int main() {
    Graph aa;
    aa.Print();
    aa.BFS(0);

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
void Graph::BFS(int nodeValue) {
    queue<int> qq;
    qq.push(nodeValue);
    visit[nodeValue] = true;
    while (!qq.empty()) {
        int data = qq.front();
        cout << data << " ";
        qq.pop();
        for (auto i = ls[nodeValue].begin(); i != ls[nodeValue].end(); i++) {
            if (!visit[*i]) {
                visit[*i] = true;
                qq.push(*i);
            }
        }
    }
}

/*
4
3
0 1
0 2
2 3

*/

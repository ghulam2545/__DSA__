// Print all connected component in graph in new line

#include <bits/stdc++.h>
using namespace std;
struct Graph {
    int v, e;
    std::vector<int> *ls;
    bool *visit;
    Graph();
    void printGraphList();
    void bfs(int nthNode);
};

int main() {
    Graph aa;
    aa.printGraphList();
    return 0;
}
Graph::Graph() {
    cin >> v >> e;
    ls = new vector<int>[v];
    int u, v;
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        ls[v].push_back(u);
        ls[u].push_back(v);
    }
    visit = new bool[v];
    for (int i = 0; i < v; i++) {
        visit[i] = false;
    }
}
void Graph::printGraphList() {
    for (auto i = 0; i < v; i++) {
        std::cout  << i << "--->" << " ";
        for (auto j : ls[i]) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}
void Graph::bfs(int nthNode) {
    visit[nthNode] = true;
    queue<int> qq;
    qq.push(nthNode);
    int num = 0;
    while (!qq.empty()) {
        num = qq.front();
        cout << num << " ";
        for (auto i = ls[num].begin(); i != ls[num].end(); i++) {
            if (!visit[(*i).first]) {
                visit[(*i).first] = true;
                qq.push((*i).first);
            }
        }
        qq.pop();
    }
}

/*
7 5
0 1
1 2
2 3
4 5
5 6

*/

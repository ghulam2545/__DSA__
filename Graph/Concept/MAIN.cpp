// Ignore meta-prog for a while...

#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class Graph {
   private:
    int _vertex, _edges;
    int u, v, w;
    bool* visit;
    vector<pair<int, int>>* ls;

   public:
    Graph();
    void MakeGraph();
    void Print();
    void DFS(int nodeVal);
    void BFS(int nodeVal);
    ~Graph() {}
};
int main() {
    Graph<int>* oo;
    oo = new Graph<int>();
    oo->MakeGraph();
    oo->Print();
    cout<<"\n";
    oo->BFS(1);

    return 0;
}

template <typename T>
Graph<T>::Graph() {
    visit = new bool[_vertex];
    for (int i = 0; i < _vertex; i++) {
        visit[i] = false;
    }
}

template <typename T>
void Graph<T>::MakeGraph() {
    cout << "Enter number of vertex : ";
    cin >> _vertex;
    cout << "Enter number of edges : ";
    cin >> _edges;
    cout << "Enter connection and weight : ";
    ls = new vector<pair<int, int>>[_vertex];
    for (int i = 0; i < _edges; i++) {
        cin >> u >> v >> w;
        ls[u].push_back({v, w});
        ls[v].push_back({u, w});
    }
}

template <typename T>
void Graph<T>::Print() {
    for (int i = 0; i < _vertex; i++) {
        cout << i << "---> ";
        vector<pair<int, int>>::iterator it;
        for (it = ls[i].begin(); it != ls[i].end(); it++) {
            cout << (*it).first << "  "
                 << "\"" << (*it).second << "\""
                 << " ";
        }
        cout << "\n";
    }
}

template <typename T>
void Graph<T>::DFS(int nodeVal) {
    visit[nodeVal] = true;
    cout << nodeVal << " ";
    vector<pair<int, int>> temp;
    for (auto it = ls[nodeVal].begin(); it != ls[nodeVal].end(); it++) {
        if (!visit[(*it).first]) {
            DFS((*it).first);
        }
    }
}

template <typename T>
void Graph<T>::BFS(int nodeVal) {
    visit[nodeVal] = true;
    queue<int> qq;
    qq.push(nodeVal);
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
9
12
0 1 10
0 8 20
7 1 30
7 8 40
2 7 70
2 3 80
7 3 60
3 4 90
4 5 120
6 4 100
6 5 110
6 8 50

*/




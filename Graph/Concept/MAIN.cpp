// Ignore meta-prog for a while...

#include <iostream>
#include <list>
#include <vector>
using namespace std;
template <typename T>
class Graph {
   private:
    int _vertex, _edges;
    int u, v, w;
    vector<pair<int, int>>* ls;

   public:
    Graph();
    void MakeGraph();
    void Print();
    ~Graph();
};
int main() {
    Graph<int>* oo;
    oo = new Graph<int>();
    oo->MakeGraph();
    oo->Print();

    return 0;
}

template <typename T>
Graph<T>::Graph() {}

template <typename T>
void Graph<T>::MakeGraph() {
    cout << "Enter number of vertex : ";
    cin >> _vertex;
    cout << "Enter number of edges : ";
    cin >> _edges;
    cout << "Enter connection and weight : ";
    ls = new vector<pair<int, int>>[_edges];
    for (int i = 0; i < _edges; i++) {
        cin >> u >> v >> w;
        ls[u].push_back({v, w});
        ls[v].push_back({u, w});
    }
}

template <typename T>
void Graph<T>::Print() {
    for (int i = 0; i < _edges; i++) {
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


/*

4
4
0 2 10
2 1 20
2 3 40
1 3 30

*/

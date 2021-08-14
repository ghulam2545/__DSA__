// Improve 

#include <bits/stdc++.h>
using namespace std;
struct Graph {
    int V, E;
    list<int> *ll;
    Graph();
    void addEdge(int &a, int &b);
    void display();
};
int main() {
    Graph g;
    int p, q;
    cout << "Enter number edges : ";
    cin >> g.E;
    for (int i = 0; i < g.E; i++) {
        cin >> p >> q;
        g.addEdge(p, q);
    }
    g.display();

    return 0;
}

Graph::Graph() {
    cout << "Enter number of vertex : ";
    cin >> V;
    ll = new list<int>[V];

}
void Graph::addEdge(int &a, int &b) {
   ll[a].push_back(b); 
   ll[b].push_back(a);
}
void Graph::display() {
    for (int i = 0; i < V; i++) {
        cout << i << "----> ";
        for (int &e : ll[i]) cout << e << " ";
        cout << "\n";
    }
}

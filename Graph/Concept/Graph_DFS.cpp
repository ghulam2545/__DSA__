#include <iostream>
#include <list>
using namespace std;
struct Graph {
    int vertex, egdes;
    bool* visit;
    int u, v;
    list<int>* ls;
    void MakeGraph();
    void Print();
    void DFS(int vertex);
};
int main() {
    Graph aa;

    aa.MakeGraph();
    aa.Print();
    cout << "\n\n";
    aa.DFS(2);

    return 0;
}
void Graph::MakeGraph() {
    cout << "Enter number of vertex : ";
    cin >> vertex;
    cout << "Enter number of edges : ";
    cin >> egdes;
    ls = new list<int>[vertex];
    cout << "Enter connection : \n";
    for (int i = 0; i < egdes; i++) {
        cin >> u >> v;
        ls[u].push_back(v);
        ls[v].push_back(u);
    }
    //
    visit = new bool[egdes];
    for (int i = 0; i < egdes; i++) {
        visit[i] = false;
    }
}

void Graph::Print() {
    for (int i = 0; i < vertex; i++) {
        cout << i << "---> ";
        for (int& e : ls[i]) cout << e << " ";
        cout << "\n";
    }
}
void Graph::DFS(int vertex) {
    visit[vertex] = true;
    list<int> temp = ls[vertex];
    cout << vertex << " ";
    for (auto i = temp.begin(); i != temp.end(); i++) {
        if (!visit[*i]) {
            DFS(*i);
        }
    }
}

/*

6
6
0 1
0 4
0 3
2 3
2 5
1 5

*/

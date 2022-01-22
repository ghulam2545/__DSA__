#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Dijkstra {
   public:
    vector<pair<int, int>>* create(const int& n, const int& m);
    vector<pair<int, int>>* addEdge(const int& src, const int& des, const int& weight);
    int* DijkstraAlgo(vector<pair<int, int>>* _graph, const int& src);

   private:
    int n_vertex;                // no of vertex
    int n_edges;                 // no of edges
    vector<pair<int, int>>* ls;  // edjecency list
    bool* visited;               // for visiting lookpu
    int* dist;                   // answer distance array
};
int main() {
    int n = 0, m = 0;
    cout << "Enter number of vertex : \n";
    cin >> n;
    cout << "Enter number of edges : \n";
    cin >> m;
    Dijkstra* obj = new Dijkstra();
    vector<pair<int, int>>* input_graph = obj->create(n, m);
    int p, q, r;
    cout << "Enter each edge cost (src - des - weight) : \n";
    while (m--) {
        cin >> p >> q >> r;
        input_graph = obj->addEdge(p, q, r);
    }
    int* ans = obj->DijkstraAlgo(input_graph, 0);
    for (int i = 0; i < n; ++i) {
        cout << "Shortest path from 0 to : ";
        cout << i << "  is  -> " << *(ans + i) << "\n";
    }
    return 0;
}
vector<pair<int, int>>* Dijkstra::create(const int& n, const int& m) {
    n_vertex = n;
    n_edges = m;
    ls = new vector<pair<int, int>>[n_vertex];
    dist = new int[n_vertex];
    for (int i = 0; i < n_vertex; ++i) {
        dist[i] = INT32_MAX;
    }
    return ls;
}
vector<pair<int, int>>* Dijkstra::addEdge(const int& src, const int& des, const int& weight) {
    ls[src].push_back(make_pair(des, weight));
    ls[des].push_back(make_pair(src, weight));
    return ls;
}
int* Dijkstra::DijkstraAlgo(vector<pair<int, int>>* _graph, const int& src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qq;
    qq.push(make_pair(0, src));
    dist[src] = 0;
    while (qq.size()) {
        int u = qq.top().second;
        qq.pop();
        for (auto e : _graph[u]) {
            int v = e.first;
            int weight = e.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                qq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

/*
7
8
0 1 30
0 4 10
0 2 20
4 2 40
1 3 80
2 3 50
3 6 70
2 5 60


5
6
0 1 10
0 2 15
0 3 50
2 1 40
2 3 30
2 4 20
*/
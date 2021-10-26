#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class weightedGraph {
    int vertex, edges;
    vector<pair<int, int>>* adj;
    bool* visited;

   public:
    weightedGraph();
    void print();
    void bfs(int start);
    void dfs(int start);
    bool cycle(int start);
    void dijk(int start);
};
weightedGraph::weightedGraph() {
    cin >> vertex >> edges;
    adj = new vector<pair<int, int>>[vertex];
    int u, v, w;
    for (int i = 0; i < edges; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    visited = new bool[vertex];
}
void weightedGraph::print() {
    for (int i = 0; i < vertex; ++i) {
        cout << i << "---> ";
        for (auto e : adj[i]) {
            cout << e.first << "|" << e.second << "    ";
        }
        cout << "\n";
    }
}
void weightedGraph::bfs(int start) {
    for (int i = 0; i < vertex; ++i) {
        visited[i] = false;
    }
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int tt = q.front();
        cout << tt << " ";
        q.pop();
        for (auto e : adj[tt]) {
            if (!visited[e.first]) {
                visited[e.first] = true;
                q.push(e.first);
            }
        }
    }
}
void weightedGraph::dfs(int start) {
    for (int i = 0; i < vertex; ++i) {
        visited[i] = false;
    }
    stack<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int tt = q.top();
        cout << tt << " ";
        q.pop();
        for (auto e : adj[tt]) {
            if (!visited[e.first]) {
                visited[e.first] = true;
                q.push(e.first);
            }
        }
    }
}
bool weightedGraph::cycle(int start) {
    int visited[vertex];
    for (int i = 0; i < vertex; ++i) {
        visited[i] = -1;
    }
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while (!q.empty()) {
        int tt = q.front();
        visited[tt] = 1;
        q.pop();
        for (auto e : adj[tt]) {
            if (visited[e.first] == 0) {
                return true;
            } else if (visited[e.first] == -1) {
                visited[e.first] = 0;
                q.push(e.first);
            }
        }
    }
    return false;
}
void weightedGraph::dijk(int start) {
    int dist[vertex];
    for (int i = 0; i < vertex; ++i) {
        dist[i] = 999;
    }
    // distance and node value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int curr_node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        for (auto e : adj[curr_node]) {
            if (curr_dist + e.second < dist[e.first]) {
                dist[e.first] = curr_dist + e.second;
                pq.push(make_pair(dist[e.first], e.first));
            }
        }
    }
    for (int i = 0; i < vertex; ++i) {
        cout << i << "  " << dist[i] << "\n";
    }
}
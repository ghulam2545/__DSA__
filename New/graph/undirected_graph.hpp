#ifndef UNDIRECTED_GRAPH_HPP
#define UNDIRECTED_GRAPH_HPP

#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class master {
   public:
    vector<pair<int, int>>* create(const int& a, const int& b);
    vector<pair<int, int>>* addEdge(const int& src, const int& des, const int& weight);
    void print(vector<pair<int, int>>* out);
    set<tuple<int, int, int>>* kruskal(vector<pair<int, int>>* gg);  // sign of returned graph is diff
    set<tuple<int, int, int>>* prim(vector<pair<int, int>>* gg);

    // disjoint
    int Find(const int& data);
    void Union(const int& a, const int& b);

   private:
    int vertex;
    int edges;
    vector<pair<int, int>>* adj;
    bool* visited;
    int* parent;
};

vector<pair<int, int>>* master::create(const int& a, const int& b) {
    vertex = a;
    edges = b;
    adj = new vector<pair<int, int>>[vertex];
    parent = new int[vertex];
    for (int i = 0; i < vertex; ++i) {
        parent[i] = i;
    }
    visited = new bool[vertex];
    for (int i = 0; i < vertex; ++i) {
        visited[i] = false;
    }
    return adj;
}

vector<pair<int, int>>* master::addEdge(const int& src, const int& des, const int& weight) {
    adj[src].push_back(make_pair(des, weight));
    adj[des].push_back(make_pair(src, weight));
    return adj;
}

void master::print(vector<pair<int, int>>* out) {
    for (auto i = 0; i < vertex; ++i) {
        cout << i << "--> ";
        for (auto e : adj[i]) {
            cout << e.first << " " << e.second << "    ";
        }
        cout << "\n";
    }
}

int master::Find(const int& data) {
    if (data == parent[data]) {
        return data;
    } else {
        int res = Find(parent[data]);
        parent[data] = res;
        return res;
    }
}

void master::Union(const int& a, const int& b) {
    int first = Find(a);
    int second = Find(b);
    if (first != second) {
        parent[first] = second;
    }
}

set<tuple<int, int, int>>* master::kruskal(vector<pair<int, int>>* gg) {
    set<tuple<int, int, int>> allEdges;
    for (int i = 0; i < vertex; ++i) {
        for (auto e : gg[i]) {
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(e.first);
            sort(temp.begin(), temp.end());
            int weight = e.second;
            allEdges.insert(make_tuple(weight, temp[0], temp[1]));
        }
    }
    set<tuple<int, int, int>> ansEdges;
    int ans = 0;
    for (auto e : allEdges) {
        int first = Find(get<1>(e));
        int second = Find(get<2>(e));
        if (first != second) {
            ++ans;
            ansEdges.insert(make_tuple(get<0>(e), get<1>(e), get<2>(e)));
            Union(first, second);
        }
        if (ans == edges - 1) break;
    }
    return ansEdges;
}

set<tuple<int, int, int>>* master::prim(vector<pair<int, int>>* gg) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push()
    // I think using edgeList will be easier
}

#endif

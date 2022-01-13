#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class master {
   public:
    vector<pair<int, int>>* create(const int& n, const int& m);
    vector<pair<int, int>>* addEdge(const int& src, const int& des, const int& weight);
    int* dijk(vector<pair<int, int>>* gg, const int& src);
    void print(vector<pair<int, int>>* out);

   private:
    int vertex;
    int edges;
    vector<pair<int, int>>* ls;
    bool* visited;
    int* dist;
};

int main() {
    int n, m;
    cin >> n >> m;
    master* oo = new master();
    vector<pair<int, int>>* myG = oo->create(n, m);
    int p, q, w;
    while (m--) {
        cin >> p >> q >> w;
        myG = oo->addEdge(p, q, w);
    }

    // oo->print(myG);
    int* ans = oo->dijk(myG, 0);
    for (int i = 0; i < n; ++i) {
        cout << "Shortest path from 0 to : ";
        cout << i << "  is  -> " << *(ans + i) << "\n";
    }
    return 0;
}

vector<pair<int, int>>* master::create(const int& n, const int& m) {
    vertex = n;
    edges = m;
    ls = new vector<pair<int, int>>[vertex];
    dist = new int[vertex];
    for (int i = 0; i < vertex; ++i) {
        dist[i] = INT32_MAX;
    }
    return ls;
}

vector<pair<int, int>>* master::addEdge(const int& src, const int& des, const int& weight) {
    ls[src].push_back(make_pair(des, weight));
    ls[des].push_back(make_pair(src, weight));
    return ls;
}

void master::print(vector<pair<int, int>>* out) {
    for (int i = 0; i < vertex; ++i) {
        cout << i << "--> ";
        for (auto e : ls[i]) {
            cout << e.first << " " << e.second << "   ";
        }
        cout << "\n";
    }
}

int* master::dijk(vector<pair<int, int>>* gg, const int& src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qq;
    qq.push(make_pair(0, src));
    dist[src] = 0;
    while (qq.size()) {
        int weight = qq.top().first;
        int node = qq.top().second;
        qq.pop();
        // relaxtation
        for (auto e : gg[node]) {
            if (weight + e.second < dist[e.first]) {
                dist[e.first] = weight + e.second;
                qq.push(make_pair(e.second, e.first));
            }
        }
    }
    return dist;
}

/*
5
6
0 1 10
0 2 15
0 3 50
2 1 40
2 3 30
2 4 20

*/
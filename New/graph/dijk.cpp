// dijk algo

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
    cout << "start -- \n";
    int n, m;
    cin >> n >> m;
    master* oo = new master();
    vector<pair<int, int>>* myG = oo->create(n, m);
    int p, q, w;
    while (m--) {
        cin >> p >> q >> w;
        myG = oo->addEdge(p, q, w);
    }

    oo->print(myG);

    cout << "\nend";
    return 0;
}

vector<pair<int, int>>* master::create(const int& n, const int& m) {
    vertex = n;
    edges = m;
    ls = new vector<pair<int, int>>[vertex];
    visited = new bool[vertex];
    for (int i = 0; i < vertex; ++i) {
        visited[i] = false;
    }
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
    // Do complete

    visited[src] = true;
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qq;
    qq.push(make_pair(0, src));
    while (qq.size()) {
        int node = qq.top().second;
        int weight = qq.top().first;
        qq.pop();
        if () {
        }
    }
}

/*

6
7
0 1 10
0 3 20
1 5 80
1 2 30
2 3 40
3 4 50
4 5 90

*/
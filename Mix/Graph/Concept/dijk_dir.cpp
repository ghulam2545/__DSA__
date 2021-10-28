#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class graph {
    int n, m;
    vector<pair<int, int>> *ls;

   public:
    graph();
    void dijk(int start);
};
int main() {
    cout << "start ---> \n";
    graph gg;
    cout << "\n";
    gg.dijk(1);
    return 0;
}
graph::graph() {
    cin >> n >> m;
    ls = new vector<pair<int, int>>[n];
    int a, b, w;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        ls[a - 1].push_back(make_pair(b - 1, w));
    }
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "--> ";
        for (auto e : ls[i]) {
            cout << e.first + 1 << " | " << e.second << "   ";
        }
        cout << "\n";
    }
}
void graph::dijk(int start) {
    int dist[n];
    for (int i = 0; i < n; ++i) {
        dist[i] = 999;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start - 1));
    dist[start - 1] = 0;
    while (!pq.empty()) {
        int val = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for (auto e : ls[val]) {
            if (weight + e.second < dist[e.first]) {
                dist[e.first] = weight + e.second;
                pq.push(make_pair(dist[e.first], e.first));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " " << dist[i] << "\n";
    }
}

/*
7
10
1 6 30
6 7 35
1 2 10
2 3 20
3 5 5
5 7 7
3 4 15
4 1 25
4 7 20
4 5 12
*/
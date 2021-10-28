#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class g {
    int vertex;
    int edges;
    vector<pair<int, int>> *ls;

   public:
    g();
    void dijk(int start);
};
int main() {
    g gg;
    cout << "\n";
    gg.dijk(5);
    return 0;
}
g::g() {
    cin >> vertex >> edges;
    ls = new vector<pair<int, int>>[vertex];
    int a, b, w;
    for (int i = 0; i < edges; ++i) {
        cin >> a >> b >> w;
        ls[a - 1].push_back(make_pair(b - 1, w));
        ls[b - 1].push_back(make_pair(a - 1, w));
    }
    for (int i = 0; i < vertex; ++i) {
        cout << i + 1 << " --> ";
        for (auto e : ls[i]) {
            cout << e.first + 1 << " | " << e.second << "   ";
        }
        cout << "\n";
    }
}
void g::dijk(int start) {
    int dist[vertex];
    for (int i = 0; i < vertex; ++i) {
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
    for (int i = 0; i < vertex; ++i) {
        cout << i + 1 << "  " << dist[i] << "\n";
    }
}

/*
6
10
1 2 16
1 6 21
1 5 19
2 3 5
2 4 6
2 6 11
5 6 33
5 4 18
6 4 14
4 3 10
*/
#include <iostream>
#include <utility>
#include <vector>

#include "undirected_graph.hpp"
using namespace std;
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
    // oo->print(myG);
    myG = oo->kruskal(myG);

    return 0;
}

/*

7
9
0 2 30
0 6 40
0 1 50
1 3 70
1 4 80
1 5 20
3 6 60
2 5 10
5 4 90

*/
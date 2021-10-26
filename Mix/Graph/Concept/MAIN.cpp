#include <iostream>

#include "weightedG.h"
using namespace std;
int main() {
    cout << "start --> \n";
    weightedGraph gg;
    gg.print();
    cout << "\nbfs : ";
    gg.bfs(3);
    cout << "\ndfs : ";
    gg.dfs(3);
    cout << "\n";
    gg.dijk(3);
    cout << "\ncycle : " << gg.cycle(2);
    return 0;
}

/*
5
6
1 0 40
1 2 50
1 4 30
1 3 30
0 4 10
3 4 20

3
2
1 0 10
1 2 20
*/
#include <iostream>
#include <queue>
#include <vector>
struct Graph {
    int vv, ee;
    std::vector<int> *ls;
    bool *vis;
    Graph();
    void PrintGraphList();
    void bfs(int nthNode);
    void bfs2();
};
int main() {
    std::cout << "Hello Graph : \n\n";
    Graph aa;
    aa.PrintGraphList();
//    std::cout<<"bfs traversal by specified node\n";
//	aa.bfs(0);
	std::cout<<"bfs traversal for each component";
    aa.bfs2();
    return 0;
}
Graph::Graph() {
    std::cin >> vv >> ee;
    ls = new std::vector<int>[vv];
    int u, v;
    for (int i = 0; i < ee; i++) {
        std::cin >> u >> v;
        ls[u].push_back(v);
        ls[v].push_back(u);
    }
    vis = new bool[vv];
    for (int i = 0; i < vv; i++) {
        vis[i] = false;
    }
}
void Graph::PrintGraphList() {
    for (auto i = 0; i < vv; i++) {
        std::cout << i << "---> "
                  << " ";
        for (auto j : ls[i]) std::cout << j << " ";
        std::cout << "\n";
    }
}
void Graph::bfs(int nthNode) {
    vis[nthNode] = true;
    std::queue<int> qq;
    qq.push(nthNode);
    // std::cout << nthNode << " ";
    while (!qq.empty()) {
        int num = qq.front();
        vis[num] = true;
        std::cout << num << " ";
        for (auto e = ls[num].begin(); e != ls[num].end(); e++) {
            if (vis[*e] == false) {
                qq.push(*e);
            }
        }
        qq.pop();
    }
}
void Graph::bfs2() {
	int ans = 0;
	
    for (int i = 0; i < vv; i++) {
        if (vis[i] == false) {
        	std::cout<<"\n";
        	ans++;
            Graph::bfs(i);
        }	
    }
    std::cout<<"\n\nTotal number of component\n"<<ans;
}
/*

11 7
2 1
2 0
6 7 
6 4
4 5
9 8 
9 10

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Graph {
    int _v, _e;
    int u, v;
    vector<int>* ls;
    bool* visit;
    Graph();
    void Print();
    void BFS(int nodeValue);
};
int main() {
    Graph aa;
    aa.Print();
    aa.BFS(2);

    return 0;
}
Graph::Graph() {
    cin >> _v >> _e;
    ls = new vector<int>[_v];
    for (int i = 0; i < _e; i++) {
        cin >> u >> v;
        ls[u].push_back(v);
        ls[v].push_back(u);
    }
    
}
void Graph::Print() {
    for (int i = 0; i < _v; i++) {
        cout << i << "----> ";
        for(auto it=ls[i].begin(); it!=ls[i].end(); it++) {
        	cout<<(*it)<<" ";
		}
        cout << "\n";
    }
    cout << "\n\n\n\n";
}

void Graph::BFS(int nodeValue) {
	visit = new bool[_v];
    for (int i = 0; i < _v; i++) {
        visit[i] = false;
    }
    queue<int> qq;
    qq.push(nodeValue);
    visit[nodeValue] = true;
    int num = 0;
    while (!qq.empty()) {
        num = qq.front();
        cout << num << " ";
        qq.pop();
        for (auto i = ls[num].begin(); i != ls[num].end(); i++) {
            if (!visit[*i]) {
                visit[*i] = true;
                qq.push(*i);
            }
        }
        
    }
}

/*
6
7
1 0
1 3
1 4
0 4
4 5
5 2 
2 3

*/

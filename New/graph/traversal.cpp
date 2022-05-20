/**
 * @file Z.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class master {
   public:
    master() {}
    ~master() {}

    vector<int> *build(int n, int m);
    vector<int> *addEdge(vector<int> *ls, int src, int des);

    void dfs(vector<int> *ls, int src);    // recursive
    void n_dfs(vector<int> *ls, int src);  // non-recursive

    void bfs(vector<int> *ls, int src);    // recursive (X)
    void n_bfs(vector<int> *ls, int src);  // non-recursive

   private:
    int n;
    int m;
    vector<int> *ls;
    bool *vis;
};

int main() {
    int n = 6;
    int m = 7;
    vector<vector<int>> in = {{0, 1}, {0, 3}, {1, 5}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};

    master *oo = new master();
    auto gg = oo->build(n, m);
    for (int i = 0; i < m; ++i) {
        auto src = in[i][0];
        auto des = in[i][1];
        gg = oo->addEdge(gg, src, des);
    }

    // do'nt mess up with me I'm using same vis array...
    // oo->dfs(gg, 1);
    // oo->n_dfs(gg, 1);
    // oo->bfs(gg, 0);

    return 0;
}

vector<int> *master::build(int n, int m) {
    this->n = n;
    this->m = m;
    ls = new vector<int>[n];
    vis = new bool[n];
    memset(vis, false, sizeof(vis));
    return ls;
}

vector<int> *master::addEdge(vector<int> *ls, int src, int des) {
    ls[src].push_back(des);
    ls[des].push_back(src);
    return ls;
}

void master::dfs(vector<int> *ls, int src) {
    vis[src] = true;
    cout << src << " ";
    for (auto &e : ls[src]) {
        if (!vis[e]) {
            vis[e] = true;
            dfs(ls, e);
        }
    }
}

void master::n_dfs(vector<int> *ls, int src) {
    vis[src] = true;
    stack<int> ss;
    ss.push(src);
    while (ss.size()) {
        auto node = ss.top();
        ss.pop();
        cout << node << " ";
        for (auto &e : ls[node]) {
            if (!vis[e]) {
                vis[e] = true;
                ss.push(e);
            }
        }
    }
}

void master::bfs(vector<int> *ls, int src) {
    vis[src] = true;
    queue<int> qq;
    qq.push(src);
    while (qq.size()) {
        auto node = qq.front();
        qq.pop();
        cout << node << " ";
        for (auto &e : ls[node]) {
            if (!vis[e]) {
                vis[e] = true;
                qq.push(e);
            }
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
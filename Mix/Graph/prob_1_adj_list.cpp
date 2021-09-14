#include <bits/stdc++.h>
using namespace std;
struct Graph {
    int v, e;
    void Graph_Pro();
    int mapping(char& data);
    void printVec(vector<char>& p);
};
int main() {
    Graph a;
    a.Graph_Pro();
    return 0;
}
void Graph::Graph_Pro() {
    Graph aa;
    cout << "Enter number of vertex : ";
    cin >> v;
    cout << "Enter number of edges : ";
    cin >> e;
    vector<char> vv[v];
    cout << "Enter vertex data : ";
    char _vData;
    for (int i = 0; i < v; i++) {
        cin >> _vData;
        vv[i].push_back(_vData);
    }
    cout << "Enter connections : ";
    char a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        vv[aa.mapping(a)].push_back(b);
    }
    for (int i = 0; i < v; i++) {
        aa.printVec(vv[i]);
    }
}
int Graph::mapping(char& data) {
    map<char, int> m;
    for (char i = 'A'; i <= 'Z'; i++) {
        m[i] = (int)i - 65;
    }
    return m[data];
}
void Graph::printVec(vector<char>& p) {
    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

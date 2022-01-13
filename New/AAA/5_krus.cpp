#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct edges {
    int source;
    int dest;
    int weight;
};
class master : public edges {
   public:
    vector<edges> create(const int& n, const int& m);
    vector<edges> addEdge(vector<edges> input, const int& src, const int& des, const int& wt);
    void print(vector<edges> input);
    bool cmp(edges a, edges b);
    int findParent(const int& ver, int* parent);
    vector<edges> kruskal(vector<edges> input, const int& n, const int& m);

   private:
    int nVertex;
    int nEdges;
    vector<edges> input;
    vector<edges> output;
    int* parent;
};
int main() {
    int n, m;
    cin >> n >> m;
    master* oo = new master();
    vector<edges> myG = oo->create(n, m);
    int p, q, r;
    while (m--) {
        cin >> p >> q >> r;
        myG = oo->addEdge(myG, p, q, r);
    }
    // oo->print(myG);

    cout << "\nEdges for minimum spanning tree : \n";
    cout << "Edges : Weight \n";
    vector<edges> ans = oo->kruskal(myG, n, m);
    oo->print(ans);

    return 0;
}

vector<edges> master::create(const int& n, const int& m) {
    nVertex = n;
    nEdges = m;
    parent = new int[nVertex];
    return input;
}
vector<edges> master::addEdge(vector<edges> input, const int& src, const int& des, const int& wt) {
    edges other;
    other.source = src;
    other.dest = des;
    other.weight = wt;
    input.push_back(other);
    return input;
}
void master::print(vector<edges> input) {
    for (int i = 0; i < input.size(); ++i) {
        cout << input[i].source << " - " << input[i].dest << " : " << input[i].weight << "\n";
    }
}
bool master::cmp(edges a, edges b) { return a.weight < b.weight; }
int master::findParent(const int& ver, int* parent) {
    if (parent[ver] == ver) return ver;
    return findParent(parent[ver], parent);
}
vector<edges> master::kruskal(vector<edges> input, const int& n, const int& m) {
    // sorting edges corresponding to their weight
    for (int i = 0; i < input.size() - 1; ++i) {
        int minWeight = input[i].weight;
        int index = i;
        for (int j = i + 1; j < input.size(); ++j) {
            if (input[j].weight < minWeight) {
                minWeight = input[j].weight;
                index = j;
            }
        }
        std::swap(input[i], input[index]);
    }
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    int cnt = 0;
    int i = 0;
    while (cnt != n - 1) {
        edges curr = input[i];

        int sParent = findParent(curr.source, parent);
        int dParent = findParent(curr.dest, parent);
        if (sParent != dParent) {
            output.push_back(curr);
            ++cnt;
            parent[sParent] = dParent;
        }
        ++i;
    }
    return output;
}

/*
4
5
0 1 10
1 2 30
0 2 20
0 3 40
2 3 50


*/

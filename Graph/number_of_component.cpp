// no of connected component (1-based indexing)

#include <iostream>
#include <queue>
#include <vector>
#define MOD (uint64_t)1000000007
using namespace std;

class Graph
{
    int vv, ee;
    std::vector<int> *ls;
    bool *visit;

public:
    Graph(int vv, int ee);
    void addEdge(int src, int des);
    void bfs(int nthNode);
    void connCom();
};

int main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        int _vertex, _edge;
        cin >> _vertex >> _edge;
        Graph oo(_vertex, _edge);

        int u, v;
        for (int i = 0; i < _edge; i++)
        {
            cin >> u >> v;
            oo.addEdge(u, v);
        }
        cout << "\n";
        oo.connCom();
    }

    return 0;
}

Graph::Graph(int vv, int ee)
{
    this->vv = vv;
    this->ee = ee;
    ls = new vector<int>[vv+1];
    visit = new bool[vv+1];
    for (int i = 1; i <= vv; i++)
    {
        visit[i] = false;
    }
}
void Graph::addEdge(int src, int des)
{
    ls[src].push_back(des);
    ls[des].push_back(src);
}
void Graph::connCom()
{
    int ans = 0;
    for (int i = 1; i <= vv; i++)
    {
        if (visit[i] == false)
        {
            ++ans;
            cout<<"\n";
            bfs(i);
        }
    }
    cout << "\n" << ans << "\n";
}

void Graph::bfs(int nthNode)
{
	int nn = 0;
    visit[nthNode] = true;
    std::queue<int> storage;
    storage.push(nthNode);
    while (!storage.empty())
    {
        int num = storage.front();
        cout << num << " ";
        storage.pop();
        for (auto i : ls[num])
        {
            if (visit[i] == false)
            {
                storage.push(i);
                visit[i] = true;
            }
        }
        ++nn;
    }
	
	cout<<"number of nodes in each component : "<<nn<<"\n\n";
}

/*

5 3
1 2 
1 3 
2 3

*/

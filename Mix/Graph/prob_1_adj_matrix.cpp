#include <iostream>
#include <map>
struct Graph {
    int vertex, edges;
    void Graph_Pro();
    int mapping(char &data);
};
int main() {
    Graph g;
    g.Graph_Pro();
    return 0;
}

void Graph::Graph_Pro() {
    Graph aa;
    char _vertex_data;
    char vertex_data[vertex], u, v;
    std::cout << "Enter no of vertex : ";
    std::cin >> vertex;
    std::cout << "Enter no of edges : ";
    std::cin >> edges;
    std::cout << "Enter vertex data : ";
    bool arr[vertex][vertex];
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            arr[i][j] = false;
        }
    }

    for (int i = 0; i < vertex; i++) {
        std::cin >> _vertex_data;
        vertex_data[i] = _vertex_data;
    }
    std::cout << "Enter connections : ";
    for (int i = 0; i < edges; i++) {
        std::cin >> u >> v;
        u = toupper(u);
        v = toupper(v);  // LOL...
        arr[aa.mapping(u)][aa.mapping(v)] = true;
        arr[aa.mapping(v)][aa.mapping(u)] = true;
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int Graph::mapping(char &data) {
    std::map<char, int> m;
    for (char i = 'A'; i <= 'Z'; i++) {
        m[i] = (int)i - 65;
    }
    return m[data];
}

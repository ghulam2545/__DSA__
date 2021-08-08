// Issue...

#include <iostream>
#include <map>
struct Graph {
	int vertex, edges;
	Graph();
};
int main() {
	Graph g;
    return 0;
}

Graph::Graph() {
	bool arr[vertex][vertex];	
	char vertex_data, u, v;
	std::map<char, int> mp;

	std::cout<<"Enter no of vertex : ";
	std::cin>>vertex;
	std::cout<<"Enter no of edges : ";
	std::cin>>edges;
	std::cout<<"Enter vertex data : ";

	for(int i=0; i<vertex; i++) {
		for(int j=0; j<vertex; j++) {
			arr[i][j] = false;
		}
	}
	
	for(int i=0; i<vertex; i++) {
		std::cin>>vertex_data;
		mp[vertex_data] = i;
	}
	std::cout<<"Enter connections : ";
	
	for(int i=0; i<edges; i++) {
		std::cin>>u>>v;
		arr[mp[u]][mp[v]] = true;
		arr[mp[v]][mp[u]] = true;
	}

	for(int i=0; i<vertex; i++) {
		for(int j=0; j<vertex; j++) {
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<"\n";
	}


}

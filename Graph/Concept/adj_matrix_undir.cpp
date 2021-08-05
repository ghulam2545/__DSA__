#include <iostream>
#include <vector>
/*
		1 ------------2
		|\			  |	
		|	\		  |
		|		\	  |
		|			\ |
		4--------------3
*/
int main() {
	unsigned int v, e;
	std::cin>>v>>e;
	bool a[v][v];
	for(int i=1; i<=v; i++)
		for(int j=1; j<=v; j++) 
			a[i][j] = false;
	
	int _u,_v;
	for(int i=0; i<e; i++) {
		std::cin>>_u>>_v;
		a[_u][_v] = true;
		a[_v][_u] = true;
	}
	
	for(int i=1; i<=v; i++) {
		for(int j=1; j<=v; j++) {
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	
	return 0;
}

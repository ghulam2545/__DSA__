#include<iostream>

struct Search {
	void no_repetition_search();
};
int main() {
	
	
	
	
	return 0;
}

void Search::no_repetition_search() {
	const std::string name = "abcgrtyeuwioqmlz";
	int size = name.size();
	int arr[size];
	for(int i=0; i<size; i++) {
		arr[i] = name[i];
	}
}
#include <iostream>
#include <map>

struct Map {
	std::map<int, std::string> mm;
	void createMap();
	void showMap();
	void accessValue(int& key);
	void erase();
};

int main() {
	Map m;
	m.createMap();
	m.showMap();
	
	int num = 3;
	m.accessValue(num);
	num = 6;
	m.accessValue(num);
	
	m.erase();
	
	return 0;
}
void Map::createMap() {
	std::string subj[] = {"physics", "math", "chemistry", "biology", "urdu", "english", "economy", "social", "commerce"};
	int size = sizeof(subj)/sizeof(subj[0]);
	
	std::pair<int, std::string> p[size];
	for(int i=0; i<size; i++) {
		p[i] = make_pair(i+1, subj[i]);
	}
	
	for(int i=0; i<size; i++) {
		mm.insert(p[i]);
	}
}
void Map::showMap() {
	// for(auto& e:mm) {
	// 	std::cout<<e.first<<"   "<<e.second<<"\n";
	// }
	std::map<int, std::string>::iterator it;
	for(it=mm.begin(); it!=mm.end(); it++) {
		std::cout<<(*it).first<<"  "<<(*it).second<<"\n";
	}
}
void Map::accessValue(int& key) {
	std::cout<<"\n";
	std::cout<<mm[key];
}
void Map::erase() {
	mm.clear();
}

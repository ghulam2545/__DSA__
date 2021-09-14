#include <iostream>
#include <vector>
using namespace std;
class Hash {
   private:
    int capacity;
    int pos;
    vector<int>* table;

   public:
    int hashIndex(int& key);
    void makeHash(int* arr, int size);
    void insert(int data);
    void remove(int data);
    bool search(int data);
    void print();
};

int main() {
    int num[] = {12, 34, 67, 54, 66, 87, 33, 90, 36, 27, 63};
    int n = sizeof(num) / sizeof(num[0]);
    Hash* aa = new Hash();
    aa->makeHash(num, n);
    aa->print();
    
    
    
    return 0;
}

int Hash::hashIndex(int& key) {
	return key % capacity;
}
void Hash::makeHash(int* arr, int size) {
    capacity = 11;
    table = new vector<int>[capacity];
    for (int i = 0; i < size; i++) {
        pos = hashIndex(arr[i]);
        table[pos].push_back(arr[i]);
    }
}
void Hash::print() {
    for (int i = 0; i < capacity; i++) {
        cout << i << "---> ";
        for (int& e : table[i]) cout << e << " ";
        cout << "\n";
    }
}
void Hash::insert(int data) {
    pos = hashIndex(data);
    table[pos].push_back(data);
}
void Hash::remove(int data) {
    pos = hashIndex(data);
    try {
    	if(table[pos].size() == 1) {
    		throw 1;
		}
		else {
			for(auto i = table[pos].begin(); i != table[pos].end(); i++) {
	    		if(data == (*i)) {
	    			table[pos].erase(i);
				}
			}	
		}
	}
	catch(...) {
		table[pos].pop_back();
	}
}
bool Hash::search(int data) {
    pos = hashIndex(data);
    bool ans = false;
    for (int& e : table[pos]) {
        if (e == data) {
            ans = true;
        }
    }
    return ans;
}

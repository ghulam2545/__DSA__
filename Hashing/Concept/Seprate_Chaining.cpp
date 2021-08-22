#include <iostream>
#include <vector>
using namespace std;
class Hash {
   public:
    int tableSize;
    vector<int>* table;
    int Hashfn(int key);
    void CreateHash(int* arr, int& size);
    void Insert(int data);
    bool Availabality(int data);
    void Print();
};
int main() {
    int num[] = {78, 76, 90, 45, 33, 45, 32, 34, 78, 55};
    int n = sizeof(num) / sizeof(num[0]);
    Hash aa;
    aa.CreateHash(num, n);
    aa.Insert(22);
    aa.Insert(33);
    aa.Print();
    cout<<"\n\n"<<aa.Availabality(76);
	cout<<"\n\n"<<aa.Availabality(11);
    return 0;
}

int Hash::Hashfn(int key) { return key % tableSize; }
void Hash::CreateHash(int* arr, int& size) {
    tableSize = 10;
    table = new vector<int>[tableSize];
    for (int i = 0; i < size; i++) {
        table[Hash::Hashfn(arr[i])].push_back(arr[i]);
    }
}
void Hash::Insert(int data) { table[Hash::Hashfn(data)].push_back(data); }
bool Hash::Availabality(int data) {
    int hashVal = Hash::Hashfn(data);
    bool ans = false;
    for (int& e : table[hashVal]) {
        if (e == data) {
            ans = true;
        }
    }
    return ans;
}

void Hash::Print() {
    for (int i = 0; i < tableSize; i++) {
        cout << i << "---> ";
        for (int& e : table[i]) cout << e << " ";
        cout << "\n";
    }
}

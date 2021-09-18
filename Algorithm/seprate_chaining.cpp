// we have multiple string and has to find in O(1)

#include <iostream>
#include <unordered_map>
#include <vector>
class Hashing {
    std::unordered_map<int, std::string> *table;

   public:
    Hashing();
    int hashFunc(const std::string &data);
};

int main() {
    std::vector<std::string> allNames = {"manuu", "rafeeq", "jameel", "saba", "noor", "ali"};
    Hashing *ins = new Hashing();
    for (int i = 0; i < allNames.size(); i++) {
        int key = ins->hashFunc(allNames[i]);
        // issue
        // (ins->table).insert({key, allNames[i]});
    }
    for (int i = 0; i < allNames.size(); i++) {
        // std::cout << "Key ; " << ins->table[i].first;
    }

    return 0;
}
Hashing::Hashing() { table = new std::unordered_map<int, std::string>; }
int Hashing::hashFunc(const std::string &data) {
    int temp = 0;
    int allSum = 0;
    for (int i = 0; i < data.size(); i++) {
        temp = data[i];
        allSum += temp;
    }
    return allSum;
}
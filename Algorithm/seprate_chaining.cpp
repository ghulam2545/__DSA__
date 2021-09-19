// // we have multiple string and has to find in O(1)

// #include <iostream>
// #include <unordered_map>
// #include <vector>
// class Hashing {
//    public:
//     std::unordered_map<int, std::string> *table;
//     Hashing();
//     int hashFunc(const std::string &data);
// };

// int main() {
//     std::vector<std::string> allNames = {"manuu", "rafeeq", "jameel", "saba", "noor", "ali"};
//     Hashing *ins = new Hashing();
//     for (int i = 0; i < allNames.size(); i++) {
//         int key = ins->hashFunc(allNames[i]);
//         ins->table->insert({key, allNames[i]});
//     }
//     for (int i = 0; i < allNames.size(); i++) {
//         std::cout << ins->table[i] << "\n";
//     }

//     return 0;
// }
// Hashing::Hashing() { table = new std::unordered_map<int, std::string>; }
// int Hashing::hashFunc(const std::string &data) {
//     int temp = 0;
//     int allSum = 0;
//     for (int i = 0; i < data.size(); i++) {
//         temp = data[i];
//         allSum += temp;
//     }
//     return allSum;
// }

#include <algorithm>
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> m;
    m.insert({10, "one"});
    m.insert({20, "two"});
    m.insert({30, "three"});
    m.insert({10, "one"});
    // reverse(m.begin(), m.end());
    for (auto i = m.begin(); i != m.end(); i++) {
        std::cout << i->first << "  " << i->second << "\n";
    }

    return 0;
}
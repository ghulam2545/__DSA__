/**
 *
 * Manual implementation
 * we have multiple string ans has to find given string in O(1)
 * considering no all distict string (not dealing if collision occur)
 *
 */
#include <cstdint>
#include <iostream>
#include <typeinfo>
#include <unordered_map>
class Hashing {
   public:
    // this will give the hash value of string
    uint32_t hashFn(const std::string &str);
};
int main() {
    const std::string name[] = {"ali", "saba", "noor", "khan", "saleem", "nawab"};
    int size = sizeof(name) / sizeof(name[0]);
    Hashing *instance = new Hashing();
    std::unordered_map<int, std::string> data;
    for (int i = 0; i < size; ++i) {
        uint32_t key = instance->hashFn(name[i]);
        data.insert({key, name[i]});
    }
    for (auto i : data) {
        std::cout << i.first << "  " << i.second << "\n";
    }

    // user intraction
    std::cout << "Enter string : ";
    std::string in;
    std::cin >> in;
    uint32_t key = instance->hashFn(in);
    std::cout << data[key] << "\n";

    return 0;
}
uint32_t Hashing::hashFn(const std::string &str) {
    uint32_t value = 0;
    for (int i = 0; i < str.size(); ++i) {
        value += (int)str[i];
    }
    return value;
}
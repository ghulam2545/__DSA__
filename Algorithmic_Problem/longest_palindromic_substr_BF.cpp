#include <iostream>
bool isPalindrome(std::string& s) {
    bool ans = true;
    for (int i = 0; i <= (s.size() / 2); i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            ans = false;
        }
    }
    return ans;
}
int main() {
    std::string str = "abcbcabbacba";
    std::string newStr = "";
    std::string ansStr = "";
    int size = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            newStr += str[j];
            if (isPalindrome(newStr)) {
                if (newStr.size() > size) {
                    size = newStr.size();
                    ansStr = newStr;
                }
            }
        }
        newStr = "";
    }
    std::cout << size << "  " << ansStr;
    return 0;
}

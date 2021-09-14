#include <iostream>
struct Linear_Search {

    // simple linear search --  O(n)
    constexpr bool searching_1(int *arr, const int &n, const int &toSearch);

    // linear seaching by both directional  --  ~O(n)
    constexpr bool searching_2(int *arr, const int &n, const int &toSearch);

    // recucsive approach  --  O(n)
    constexpr bool searching_3(int *arr, int &n, const int &toSearch);
};
int main() {
    int num[] = {11, 34, 56, 32, 43, 90, 45, 78};
    const int size = sizeof(num) / sizeof(num[0]);

    Linear_Search *ins = new Linear_Search();
    std::cout << ins->searching_1(num, size, 32) << "\n";
    std::cout << ins->searching_1(num, size, 33) << "\n\n";

    std::cout << ins->searching_2(num, size, 32) << "\n";
    std::cout << ins->searching_2(num, size, 33) << "\n\n";
    return 0;
}
constexpr bool Linear_Search::searching_1(int *arr, const int &n, const int &toSearch) {
    bool ans = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == toSearch) {
            ans = true;
            break;
        }
    }
    return ans;
}
constexpr bool Linear_Search::searching_2(int *arr, const int &n, const int &toSearch) {
    int low = 0;
    int high = n - 1;
    int ans = false;
    while (low <= high) {
        if (arr[low] == toSearch) {
            ans = true;
            break;
        }
        if (arr[high] == toSearch) {
            ans = true;
            break;
        }
        ++low;
        --high;
    }
    return ans;
}
constexpr bool Linear_Search::searching_3(int *arr, int &n, const int &toSearch) {}

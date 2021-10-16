#include <iostream>
using namespace std;
// Question 1
// Write a recursive function that takes a number and returns the sum of all the
// numbers from zero to that number.
long long solve1(int num) { return (num == 0) ? 0 : num + solve1(num - 1); }

// Question 2
// Write a recursive function that takes a number as an input
// and returns the factorial of that number.
long long solve2(int num) { return num <= 1 ? 1 : num * solve2(num - 1); }

// Question 3
// Write a recursive function that takes a number ‘n’ and returns the
// nth number of the Fibonacci number.
long long solve3(int num) { return (num == 0 || num == 1) ? num : solve3(num - 1) + solve3(num - 2); }

// Question 4
// Write a recursive function that takes a list of numbers as an input and returns
// the product of all the numbers in the list.
long long solve4(int* arr, int size) { return (size == 0) ? 1 : arr[size - 1] * solve4(arr, size - 1); }

// Question 5
// Write a function that takes a string and returns if the string is a palindrome.
bool solve5(string s) {}
int main() {
    int n = 4;
    int a[] = {2, 3, -2, 5};
    long long ans = solve1(n);
    cout << ans << "\n";
    return 0;
}
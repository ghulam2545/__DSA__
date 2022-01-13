#include <iostream>
#include <vector>
#define Board std::vector<std::vector<bool>>
using namespace std;
class master {
   public:
    Board* create(const int& n);
    bool isSafe(Board* board, const int& row, const int& col);
    bool solve(Board* board, const int& row, const int& n);
    void QueenProblem(const int& n);
    void print(Board* board);

   private:
    Board* board;
};
int main() {
    int n = 4;
    master* oo = new master();
    cout << "For n = " << n << " : \n";
    oo->QueenProblem(n);
    cout << "\nFor n = " << n + 2 << " : \n";
    oo->QueenProblem(n + 2);

    return 0;
}
Board* master::create(const int& n) {
    board = new Board(n, vector<bool>(n, false));
    return board;
}
bool master::isSafe(Board* board, const int& row, const int& col) {
    int n = (*board).size();
    for (int i = 0; i < row; i++)
        if ((*board)[i][col] == true) return false;
    for (int i = row, j = col; j < n && i >= 0; i--, j++)
        if ((*board)[i][j] == true) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if ((*board)[i][j] == true) return false;
    return true;
}
bool master::solve(Board* board, const int& row, const int& n) {
    if (row >= n) return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i)) {
            (*board)[row][i] = true;
            if (solve(board, row + 1, n)) return true;
            (*board)[row][i] = false;
        }
    }
    return false;
}
void master::print(Board* board) {
    int n = (*board).size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (*board)[i][j] << " ";
        }
        cout << "\n";
    }
}
void master::QueenProblem(const int& n) {
    Board* board = create(n);
    if (solve(board, 0, n) == false) {
        cout << "Solution Do not exist for " << n << " Queens.";
        return;
    }
    print(board);
}
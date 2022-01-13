#include <bits/stdc++.h>
class master {
   public:
    // Some restrictions
    master(const master&) = delete;
    master& operator=(master const&) = delete;
    master(std::vector<std::vector<double>>& distance) : master(0, distance) {}
    master(int start, std::vector<std::vector<double>>& distance);

    // Returns the optimal tour for the traveling salesman problem.
    const std::list<int>& getTour();

    // Returns the minimal tour cost.
    double getTourCost();

   private:
    const double POSITIVE_INFINITY = std::numeric_limits<double>::infinity();
    const double NEGATIVE_INFINITY = -std::numeric_limits<double>::infinity();

    int N_, start_;
    std::vector<std::vector<double>> distance_;
    std::list<int> tour_;
    double minTourCost_;
    bool ranSolver_;
    bool notIn(int elem, int subset);

    // This method generates all bit sets of size n where r bits
    // are set to one. The result is returned as a list of integer masks.
    std::list<int> combinations(int r, int n);

    // To find all the combinations of size r we need to recurse until we have
    // selected r elements , otherwise if r != 0 then we still need to select
    // an element which is found after the position of our last selected element
    void combinations(int set, int at, int r, int n, std::list<int>& subsets);

    // Solves the traveling salesman problem and caches solution.
    void solve();
};
int main() {
    // Create adjacency matrix
    int n = 6;
    std::vector<std::vector<double>> distanceMatrix(n, std::vector<double>(n, 10000));
    distanceMatrix[5][0] = 10;
    distanceMatrix[1][5] = 12;
    distanceMatrix[4][1] = 2;
    distanceMatrix[2][4] = 4;
    distanceMatrix[3][2] = 6;
    distanceMatrix[0][3] = 8;

    int startNode = 0;

    try {
        std::unique_ptr<master> solver = std::make_unique<master>(startNode, distanceMatrix);

        // Prints: [0, 3, 2, 4, 1, 5, 0]
        std::stringstream str;
        str << "Tour: [";
        for (auto node : solver->getTour()) {
            str << "-> ";
            str << node;
        }
        str << "]";
        std::cout << str.str() << std::endl;

        // Print: 42.0
        std::cout << "Tour cost: " << solver->getTourCost() << std::endl;

        solver = nullptr;
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    } catch (...) {
        std::cout << "Default Exception\n";
    }
    return 0;
}

master::master(int start, std::vector<std::vector<double>>& distance) {
    minTourCost_ = POSITIVE_INFINITY;
    ranSolver_ = false;
    N_ = distance[0].size();

    if (N_ <= 2) throw std::invalid_argument("N <= 2 not yet supported.");
    if (N_ != distance.size()) throw std::invalid_argument("Matrix must be square (n x n)");
    if (start < 0 || start >= N_) throw std::invalid_argument("Invalid start node.");
    if (N_ > 32) throw std::invalid_argument("Matrix too large! A matrix that size for the DP TSP problem with a time complexity of O(n^2*2^n) requires way too much computation for any modern home computer to handle");

    start_ = start;
    distance_ = distance;
}
const std::list<int>& master::getTour() {
    if (!ranSolver_) solve();
    return tour_;
}
double master::getTourCost() {
    if (!ranSolver_) solve();
    return minTourCost_;
}
bool master::notIn(int elem, int subset) { return ((1 << elem) & subset) == 0; }
std::list<int> master::combinations(int r, int n) {
    std::list<int> subsets;
    combinations(0, 0, r, n, subsets);
    return subsets;
}
void master::combinations(int set, int at, int r, int n, std::list<int>& subsets) {
    // Return early if there are more elements left to select than what is available.
    int elementsLeftToPick = n - at;
    if (elementsLeftToPick < r) return;

    // We selected 'r' elements so we found a valid subset!
    if (r == 0) {
        subsets.push_back(set);
    } else {
        for (int i = at; i < n; i++) {
            // Try including this element
            set ^= (1 << i);

            combinations(set, i + 1, r - 1, n, subsets);

            // Backtrack and try the instance where we did not include this element
            set ^= (1 << i);
        }
    }
}
void master::solve() {
    if (ranSolver_) return;

    int END_STATE = (1 << N_) - 1;
    std::vector<std::vector<double>> memo(N_, std::vector<double>(1 << N_, POSITIVE_INFINITY));

    // Add all outgoing edges from the starting node to memo table.
    for (int end = 0; end < N_; end++) {
        if (end == start_) continue;
        memo[end][(1 << start_) | (1 << end)] = distance_[start_][end];
    }

    for (int r = 3; r <= N_; r++) {
        for (int subset : combinations(r, N_)) {
            if (notIn(start_, subset)) continue;
            for (int next = 0; next < N_; next++) {
                if (next == start_ || notIn(next, subset)) continue;
                int subsetWithoutNext = subset ^ (1 << next);
                double minDist = POSITIVE_INFINITY;
                for (int end = 0; end < N_; end++) {
                    if (end == start_ || end == next || notIn(end, subset)) continue;
                    double newDistance = memo[end][subsetWithoutNext] + distance_[end][next];
                    if (newDistance < minDist) {
                        minDist = newDistance;
                    }
                }
                memo[next][subset] = minDist;
            }
        }
    }

    // Connect tour back to starting node and minimize cost.
    for (int i = 0; i < N_; i++) {
        if (i == start_) continue;
        double tourCost = memo[i][END_STATE] + distance_[i][start_];
        if (tourCost < minTourCost_) {
            minTourCost_ = tourCost;
        }
    }

    int lastIndex = start_;
    int state = END_STATE;
    tour_.push_front(start_);

    // Reconstruct TSP path from memo table.
    for (int i = 1; i < N_; i++) {
        int index = -1;
        for (int j = 0; j < N_; j++) {
            if (j == start_ || notIn(j, state)) continue;
            if (index == -1) index = j;
            double prevDist = memo[index][state] + distance_[index][lastIndex];
            double newDist = memo[j][state] + distance_[j][lastIndex];
            if (newDist < prevDist) {
                index = j;
            }
        }

        tour_.push_front(index);
        state = state ^ (1 << index);
        lastIndex = index;
    }

    tour_.push_front(start_);

    ranSolver_ = true;
}
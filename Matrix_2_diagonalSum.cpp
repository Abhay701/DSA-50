#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        vector<int> diagonal_p;
        vector<int> diagonal_s;
        
        // Primary diagonal
        for(int i = 0; i < mat.size(); i++) {
            diagonal_p.push_back(mat[i][i]);
        }

        // Secondary diagonal
        for(int i = 0; i < mat.size(); i++) {
            int j = mat.size() - 1 - i;
            diagonal_s.push_back(mat[i][j]);
        }

        int sum_p = 0;
        for(int i = 0; i < diagonal_p.size(); i++) {
            sum_p += diagonal_p.at(i);
        }

        int sum_s = 0;
        for(int i = 0; i < diagonal_s.size(); i++) {
            sum_s += diagonal_s.at(i);
        }

        int sum = 0;
        if(mat.size() % 2 == 0) {
            sum = sum_p + sum_s;
        } else {
            sum = sum_p + sum_s - diagonal_s.at((diagonal_p.size()) / 2); // Remove the middle element once if matrix size is odd
        }
        
        return sum;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }; // Example 3x3 matrix

    Solution solution;
    int result = solution.diagonalSum(mat); // Call diagonalSum

    cout << "Sum of primary and secondary diagonals: " << result << endl;
    return 0;
}

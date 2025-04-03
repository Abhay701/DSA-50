#include <iostream>
#include <vector>

class Solution {
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Check diagonals starting from the first row
        for (int col = 0; col < cols; col++) {
            int value = matrix[0][col];
            for (int row = 1, j = col + 1; row < rows && j < cols; row++, j++) {
                if (matrix[row][j] != value) {
                    return false;
                }
            }
        }

        // Check diagonals starting from the first column (excluding the first element)
        for (int row = 1; row < rows; row++) {
            int value = matrix[row][0];
            for (int col = 1, j = row + 1; col < cols && j < rows; col++, j++) {
                if (matrix[j][col] != value) {
                    return false;
                }
            }
        }

        return true; // All checks passed
    }
};

int main() {
    Solution solution;

    // Test case 1: Toeplitz matrix
    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {6, 5, 1, 2}
    };
    std::cout << "Matrix 1 is Toeplitz: " << (solution.isToeplitzMatrix(matrix1) ? "True" : "False") << std::endl;

    // Test case 2: Non-Toeplitz matrix
    std::vector<std::vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {6, 5, 1, 2},
        {7, 8, 9, 1}
    };
    std::cout << "Matrix 2 is Toeplitz: " << (solution.isToeplitzMatrix(matrix2) ? "True" : "False") << std::endl;

    // Test case 3: Another Toeplitz matrix
    std::vector<std::vector<int>> matrix3 = {
        {10, 20, 30},
        {40, 10, 20},
        {50, 40, 10}
    };
    std::cout << "Matrix 3 is Toeplitz: " << (solution.isToeplitzMatrix(matrix3) ? "True" : "False") << std::endl;

    // Test case 4: Another Non-Toeplitz matrix
    std::vector<std::vector<int>> matrix4 = {
        {1, 2},
        {2, 2}
    };
    std::cout << "Matrix 4 is Toeplitz: " << (solution.isToeplitzMatrix(matrix4) ? "True" : "False") << std::endl;

    return 0;
}

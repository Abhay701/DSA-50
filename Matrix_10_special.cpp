#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int special = 0; // Initialize a counter for special positions
        vector<pair<int, int>> v; // Store positions of '1's in the matrix

        // Traverse the matrix to find all '1's
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 1) {
                    v.push_back({i, j}); // Store the row and column of each '1'
                }
            }
        }
        
        // Loop through each '1' position stored in vector v
        for(int k = 0; k < v.size(); k++) {
            int x = v[k].first; // Row position of the current '1'
            int y = v[k].second; // Column position of the current '1'

            bool isSpecial = true; // Assume current position is special
            
            // Check the entire row for any other '1' in the same row
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[x][j] == 1 && j != y) { // If another '1' is found in the row
                    isSpecial = false; // Mark as not special
                    break; // Stop further row checking
                }
            }

            // Check the entire column for any other '1' if the row check passed
            if(isSpecial) {
                for(int i = 0; i < mat.size(); i++) {
                    if(mat[i][y] == 1 && i != x) { // If another '1' is found in the column
                        isSpecial = false; // Mark as not special
                        break; // Stop further column checking
                    }
                }
            }
            
            // Increment the special counter if both checks passed
            if(isSpecial) {
                special++;
            }
        }

        return special; // Return the total count of special positions
    }
};

int main() {
    Solution solution;
    
    // Example test case 1
    vector<vector<int>> mat1 = {
        {1, 0, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    cout << "Number of special positions (Test Case 1): " << solution.numSpecial(mat1) << endl; // Expected output: 1

    // Example test case 2
    vector<vector<int>> mat2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Number of special positions (Test Case 2): " << solution.numSpecial(mat2) << endl; // Expected output: 3

    // Additional test case
    vector<vector<int>> mat3 = {
        {0, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };
    cout << "Number of special positions (Test Case 3): " << solution.numSpecial(mat3) << endl; // Expected output: 4

    return 0;
}

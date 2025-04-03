#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> reshape(r, vector<int>(c));

        if (r * c != mat.size() * mat[0].size()) return mat;

        int x = 0, y = 0;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                reshape[x][y] = mat[i][j];
                y++;
                if (y == c) {
                    y = 0;
                    x++;
                }
            }
        }

        return reshape;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    int r = 1, c = 4;

    vector<vector<int>> result = solution.matrixReshape(mat, r, c);

    cout << "Reshaped matrix:\n";
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Test case 2
    mat = {{1, 2}, {3, 4}};
    r = 2, c = 4;

    result = solution.matrixReshape(mat, r, c);

    cout << "\nReshaped matrix (when reshape is not possible):\n";
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

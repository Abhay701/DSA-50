#include <bits/stdc++.h>
using namespace std;

int countNegativeNumbers(vector<vector<int>> &mat) {
    int count = 0;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] < 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Example matrix with both positive and negative numbers
    vector<vector<int>> mat = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    int negativeCount = countNegativeNumbers(mat);
    cout << "Count of negative numbers: " << negativeCount << endl;

    return 0;
}

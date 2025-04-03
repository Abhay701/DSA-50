#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> row;
        vector<int> column;
        vector<int> luckyNumber;

        // Find the minimum element in each row
        for (int i = 0; i < matrix.size(); i++)
        {
            int minRow = INT_MAX;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] <= minRow)
                {
                    minRow = matrix[i][j];
                }
            }
            row.push_back(minRow);
        }

        // Find the maximum element in each column
        for (int i = 0; i < matrix[0].size(); i++)
        {
            int maxColumn = INT_MIN;
            for (int j = 0; j < matrix.size(); j++)
            {
                if (matrix[j][i] >= maxColumn)
                {
                    maxColumn = matrix[j][i];
                }
            }
            column.push_back(maxColumn);
        }

        for (int i = 0; i < row.size(); i++)
        {
            for (int j = 0; j < column.size(); j++)
            {
                if (row[i] == column[j])
                {
                    luckyNumber.push_back(row[i]);
                }
            }
        }
        return luckyNumber;
    }
};

int main()
{
    Solution solution;

    // Test case
    vector<vector<int>> matrix = {
        {1, 10, 4, 2},
        {9, 3, 8, 7},
        {15, 16, 17, 12}};

    vector<int> result = solution.luckyNumbers(matrix);

    cout << "Lucky Numbers: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
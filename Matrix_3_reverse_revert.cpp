#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> result(image.size()); // Initialize result with the same size as image
        
        // Logic to reverse the image vector
        for(int i = 0; i < image.size(); i++) {
            for(int j = (image[i].size() - 1); j >= 0; j--) { // Use image[i].size() for the inner loop
                result[i].push_back(image[i][j]);
            }
        }

        // Logic to invert the result vector
        for(int i = 0; i < result.size(); i++) {
            for(int j = 0; j < result[i].size(); j++) { // Use result[i].size() for the inner loop
                if(result[i][j] == 0) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = 0;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> image = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}
    }; // Example input image

    Solution solution;
    vector<vector<int>> result = solution.flipAndInvertImage(image); // Call the function

    // Print the flipped and inverted image
    cout << "Flipped and Inverted Image: " << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

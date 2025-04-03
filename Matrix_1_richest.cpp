#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> amount; // total amount of a customer in all the bank accounts
        for(int i = 0; i < accounts.size(); i++) {
            int sum = 0;
            for(int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }
            amount.push_back(sum);
        }

        // Finding the maximum element
        int maxWealth = amount[0];
        for(int i = 1; i < amount.size(); i++) {
            if(amount[i] > maxWealth) {
                maxWealth = amount[i];
            }
        }

        return maxWealth;
    }
};

int main() {
    vector<vector<int>> accounts = {
        {1, 2, 3},  // Customer 1's wealth
        {3, 2, 1},  // Customer 2's wealth
        {4, 3, 2}   // Customer 3's wealth
    };
    Solution solution;
    int maxWealth = solution.maximumWealth(accounts); // Call maximumWealth

    cout << "Maximum Wealth: " << maxWealth << endl; // Output the result
    return 0;
}

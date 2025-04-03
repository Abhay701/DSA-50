#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Initialize minimum price to a large value
        int maxProfit = 0;       // Initialize maximum profit to 0

        for (int i = 0; i < prices.size(); i++) {
            // Update minPrice if the current price is lower
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Calculate profit if sold at current price
            int profit = prices[i] - minPrice;
            // Update maxProfit if the calculated profit is higher
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return maxProfit;  // Return the maximum profit found
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Sample stock prices
    Solution solution;
    int maxProfit = solution.maxProfit(prices); // Call the maxProfit function

    cout << "Maximum Profit: " << maxProfit << endl; // Output the result
    return 0;
}

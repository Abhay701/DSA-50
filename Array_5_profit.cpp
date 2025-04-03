#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum profit from stock prices
int maximumProfit(vector<int> &prices) {
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

int main() {
    int n;
    cout << "Enter the number of stock prices: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maximumProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

#include <iostream>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *               1 if num is lower than the picked number
 *               otherwise return 0
 */
int pickedNumber; // Global variable to store the picked number

// Mock implementation of the guess function
int guess(int num) {
    if (num < pickedNumber) {
        return 1; // num is lower than the picked number
    } else if (num > pickedNumber) {
        return -1; // num is higher than the picked number
    } else {
        return 0; // num is equal to the picked number
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;  // Start of the range
        int high = n; // End of the range
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the mid-point
            
            int result = guess(mid); // Call the guess API
            
            if (result == 0) {
                return mid; // Found the picked number
            } else if (result == 1) {
                low = mid + 1; // Picked number is higher
            } else {
                high = mid - 1; // Picked number is lower
            }
        }
        
        return -1; // Just in case, though the problem guarantees a solution
    }
};

int main() {
    Solution solution;

    // Set the picked number for testing
    pickedNumber = 6; // Change this to test different scenarios

    int n = 10; // Set the range upper limit
    int guessedNumber = solution.guessNumber(n);

    cout << "The picked number is: " << guessedNumber << endl; // Output the guessed number

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long long n) {
    if (n == 0 || n == 1) {
        return true;  // 0 and 1 are perfect squares
    }

    long long low = 1, high = n;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        // Check if mid*mid == n
        if ((mid * mid) == n) {
            return true;  // Found a perfect square
        } else if ((mid * mid) > n) {
            high = mid - 1;  // Decrease high if mid*mid is greater than n
        } else {
            low = mid + 1;  // Increase low if mid*mid is less than n
        }
    }

    return false;  // No perfect square found
}

int main() {
    long long num;
    cout << "Enter a number to check if it's a perfect square: ";
    cin >> num;

    if (isPerfectSquare(num)) {
        cout << num << " is a perfect square." << endl;
    } else {
        cout << num << " is not a perfect square." << endl;
    }

    return 0;
}

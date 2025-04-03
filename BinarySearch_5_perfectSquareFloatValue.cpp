#include <iostream>
using namespace std;

int floorSqrt(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int low = 1, high = n, result = 1;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        // Check if mid*mid <= n
        if ((mid * mid) <= n) {
            result = mid;
            low = mid + 1;  // Increase low to find a larger possible square root
        } else {
            high = mid - 1;  // Decrease high if mid*mid is greater than n
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int sqrtResult = floorSqrt(n);
    cout << "The floor square root of " << n << " is: " << sqrtResult << endl;

    return 0;
}

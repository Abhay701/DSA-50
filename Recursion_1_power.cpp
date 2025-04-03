#include <iostream>
#include<math.h>
using namespace std;

// bool isPowerOfTwo(int n)
// {
//     bool check = false;
//     int a = 1;
//     for (int i = 1; i <= n; i++) {
//         a *= 2;
//         if (a == n) {
//             check = true;
//             break;
//         }
//     }
//     return check;
// }

// Using Recursion
bool isPowerOfTwo(int n)
{
    // Base case: 1 is a power of two (2^0 = 1)
    cout << n << endl;
    if (n == 1)
        return true;
    // If n is less than 1 or not divisible by 2, it's not a power of two
    if (n <= 0 || n % 2 != 0)
        return false;
    // Recursive call: divide n by 2 and check again
    return isPowerOfTwo(n / 2);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n))
    {
        cout << n << " is a power of two." << endl;
    }
    else
    {
        cout << n << " is not a power of two." << endl;
    }

    return 0;
}

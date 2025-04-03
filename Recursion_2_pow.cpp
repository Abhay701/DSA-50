#include <bits/stdc++.h>
using namespace std;

// Recursive power function
long long Pow(int X, int N) {
    if (N == 0) return 1;   // Base case: any number to the power of 0 is 1
    if (X == 0) return 0;   // Base case: 0 to any positive power is 0
    return X * Pow(X, N - 1); // Multiply X with result of X^(N-1)
}

int main() {
    int X, N;
    cout << "Enter the base (X): ";
    cin >> X;
    cout << "Enter the exponent (N): ";
    cin >> N;

    long long result = Pow(X, N);
    cout << X << " raised to the power " << N << " is " << result << endl;

    return 0;
}

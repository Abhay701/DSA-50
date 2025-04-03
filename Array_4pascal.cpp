#include <bits/stdc++.h>
using namespace std;

// Function to calculate factorial
long long factorial(int t)
{
    long long f = 1;
    for (int i = 1; i <= t; i++)
    {
        f *= i;
    }
    return f;
}

// Function to calculate binomial coefficient nCr
long long nCr(int x, int y)
{
    return factorial(x) / (factorial(y) * factorial(x - y));
}

// Function to generate Pascal's triangle up to row n
vector<vector<long long>> printPascal(int n)
{
    vector<vector<long long>> pascal; // No need to initialize with size n

    // Loop to generate each row of Pascal's triangle
    for (int i = 0; i < n; i++)
    {
        vector<long long> temp; // Use long long to avoid overflow

        // Generate elements for each row
        for (int j = 0; j <= i; j++)
        {
            temp.push_back(nCr(i, j));
        }

        pascal.push_back(temp); // Add the row to the triangle
    }
    return pascal;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<long long>> pascal = printPascal(n);

        // Output the Pascal's triangle
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << pascal[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

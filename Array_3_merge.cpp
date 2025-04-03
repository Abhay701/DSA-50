#include <iostream>
#include <vector>
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Pointer to the last element of arr1's valid data
    int i = m - 1;
    // Pointer to the last element of arr2
    int j = n - 1;
    // Pointer to the last index of arr1's total space
    int k = m + n - 1;

    // Merge arr2 into arr1 starting from the end
    while (j >= 0)
    {
        // If i is still in range and arr1[i] > arr2[j], place arr1[i] at arr1[k]
        if (i >= 0 && arr1[i] > arr2[j])
        {
            arr1[k--] = arr1[i--];
        }
        // Otherwise, place arr2[j] at arr1[k]
        else
        {
            arr1[k--] = arr2[j--];
        }
    }

    // Return the merged array
    return arr1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<int> arr1(m + n); // arr1 has space for m + n elements
        vector<int> arr2(n);     // arr2 has n elements

        for (int i = 0; i < m; i++)
        {
            cin >> arr1[i]; // Input valid elements of arr1
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i]; // Input elements of arr2
        }

        vector<int> result = ninjaAndSortedArrays(arr1, arr2, m, n);

        for (int i = 0; i < m + n; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

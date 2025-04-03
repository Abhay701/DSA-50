#include <iostream>
#include <vector>
using namespace std;


vector<pair<int, int>> twoSum(vector<int>& arr, int target, int n) {
    vector<pair<int, int>> v;
    vector<bool> used(n, false);  // To track if an element is already used in a pair
    bool foundPair = false;  // To track if a valid pair is found

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;  // Skip this index if it's already used

        for (int j = i + 1; j < n; j++) {
        if (used[j]) continue;  // Skip this index if it's already used
            if (arr[i] + arr[j] == target) {
                v.push_back({arr[i], arr[j]});
                used[i] = true;  // Mark i and j as used
                used[j] = true;
                foundPair = true;
                break;  // Move to the next i after finding a valid pair
            }
        }
    }

    // If no valid pair was found, push {-1, -1}
    if (!foundPair) {
        v.push_back({-1, -1});
    }

    return v;
}

int main() {
    // Input: number of elements in the array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input: array elements
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input: target sum
    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    // Call twoSum function
    vector<pair<int, int>> result = twoSum(arr, target, n);

    // Output the result
    cout << "Pairs with sum " << target << " are:" << endl;
    for (const auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

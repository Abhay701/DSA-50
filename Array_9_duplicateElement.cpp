#include <bits/stdc++.h>
using namespace std;

// Function to find the first duplicate element
int findDuplicate(vector<int> &arr) {
    int duplicate = -1;
    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 2) {
            duplicate = arr[i];
            break; // Exit loop once the first duplicate element is found
        }
    }
    return duplicate;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findDuplicate(arr);
    if (result != -1) {
        cout << "The first duplicate element is: " << result << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element
int findMajorityElement(int arr[], int n) {
    int x = n / 2;
    int majority = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > x) {
            majority = arr[i];
        }
    }
    return majority;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findMajorityElement(arr, n);
    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element
int findPeakElement(vector<int> &arr) {
    int peak = -1;
    int s = arr.size();
    
    // Check for peaks in the middle of the array
    for (int i = 1; i < s - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            peak = i;
        }
    }
    
    // Check if the first element is a peak
    if (arr[0] > arr[1]) {
        peak = 0;
    }
    
    // Check if the last element is a peak
    if (arr[s - 1] > arr[s - 2]) {
        peak = s - 1;
    }
    
    return peak;
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
    
    int peakIndex = findPeakElement(arr);
    
    if (peakIndex != -1) {
        cout << "A peak element is found at index: " << peakIndex << endl;
    } else {
        cout << "No peak element found" << endl;
    }
    
    return 0;
}

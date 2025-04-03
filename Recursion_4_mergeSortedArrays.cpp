#include <iostream>
#include <vector>
using namespace std;

// Recursive helper function to merge arrays
void mergeRecursively(vector<int>& arr1, vector<int>& arr2, int i, int j, int k) {
    // Base case: if there are no more elements in arr2 to merge, return
    if (j < 0) return;

    // If arr1 has elements and arr1[i] > arr2[j], place arr1[i] at arr1[k]
    if (i >= 0 && arr1[i] > arr2[j]) {
        arr1[k] = arr1[i];
        mergeRecursively(arr1, arr2, i - 1, j, k - 1);
    } 
    // Otherwise, place arr2[j] at arr1[k]
    else {
        arr1[k] = arr2[j];
        mergeRecursively(arr1, arr2, i, j - 1, k - 1);
    }
}

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    // Call the recursive helper function with initial indices
    mergeRecursively(arr1, arr2, m - 1, n - 1, m + n - 1);
    return arr1;
}

int main() {
    // Example arrays (arr1 has enough space for arr2's elements)
    vector<int> arr1 = {1, 3, 5, 0, 0, 0}; // '0's are placeholders for arr2's elements
    vector<int> arr2 = {2, 4, 6};
    
    // Number of valid elements in arr1 and arr2
    int m = 3; // Number of valid elements in arr1
    int n = 3; // Number of valid elements in arr2

    // Merge arr2 into arr1
    vector<int> mergedArray = ninjaAndSortedArrays(arr1, arr2, m, n);
    
    // Print the merged array using a simple iteration loop
    cout << "Merged array: ";
    for (int i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    return 0;
}


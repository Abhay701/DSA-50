#include <iostream>
#include <vector>
using namespace std;

// Function to search for a target value in the vector
int search(vector<int> &nums, int target) {
    int index = -1;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == target) {
            index = i; // Update the index if the target is found
            break; // Break the loop once the target is found
        }
    }
    return index; // Return the index of the target, or -1 if not found
}

int main() {
    vector<int> nums;
    int n, target;

    // Prompt the user to enter the number of elements
    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    // Input the elements of the vector
    cout << "Enter the elements of the vector: ";
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // Prompt the user to enter the target value to search for
    cout << "Enter the target value to search for: ";
    cin >> target;

    // Search for the target in the vector
    int result = search(nums, target);

    // Output the result
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the vector." << endl;
    }

    return 0;
}

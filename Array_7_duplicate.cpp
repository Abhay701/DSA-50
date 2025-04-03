#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        bool check = false;
        sort(nums.begin(), nums.end()); // Sort the vector nums
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                check = true;
                break; // Exit the loop as soon as a duplicate is found
            }
        }
        return check;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 1}; // Sample vector with a duplicate
    Solution solution;

    bool hasDuplicate = solution.containsDuplicate(nums); // Call containsDuplicate

    if (hasDuplicate)
    {
        cout << "The array contains duplicates." << endl;
    }
    else
    {
        cout << "The array does not contain duplicates." << endl;
    }

    return 0;
}

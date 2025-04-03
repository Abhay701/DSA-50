
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nextGreater;
        stack<int> st;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    st.push(nums2[j]);
                    int a = 0;
                    for (int k = j + 1; k < nums2.size(); k++)
                    {
                        if (nums2[k] > st.top())
                        {
                            nextGreater.push_back(nums2[k]);
                            st.pop();
                            st.push(nums2[k]);
                            a++;
                            break;
                        }
                    }
                    if (a == 0)
                    {
                        nextGreater.push_back(-1);
                    }
                    break;
                }
            }
        }
        return nextGreater;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    cout << "Input: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2]" << endl;
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    // Test case 2
    nums1 = {2, 4};
    nums2 = {1, 2, 3, 4};
    result = solution.nextGreaterElement(nums1, nums2);

    cout << "Input: nums1 = [2, 4], nums2 = [1, 2, 3, 4]" << endl;
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for (int i = 0; i < jewels.size(); i++) {
            for (int j = 0; j < stones.size(); j++) {
                if (jewels[i] == stones[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    string jewels, stones;

    // Input jewels and stones
    cout << "Enter jewels string: ";
    cin >> jewels;
    cout << "Enter stones string: ";
    cin >> stones;

    // Call the function and display the result
    int result = solution.numJewelsInStones(jewels, stones);
    cout << "Number of jewels in stones: " << result << endl;

    return 0;
}

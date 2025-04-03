#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        // Split the input string into words
        stringstream stream(s);
        string word;
        vector<string> sorted(9);  // A maximum of 9 words

        while (stream >> word) {
            // The position is the last character of the word
            int position = word.back() - '1';  // Convert '1' to 0, '2' to 1, etc.
            word.pop_back();  // Remove the last character (number)
            sorted[position] = word;
        }

        // Construct the sorted sentence
        string result;
        for (int i = 0; i < sorted.size(); i++) {
            if (!sorted[i].empty()) {
                result += sorted[i] + " ";  // Add word followed by a space
            }
        }
        if (!result.empty()) {
            result.pop_back();  // Remove the trailing space
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string input1 = "Myself2 Me1 I4 and3";
    string output1 = solution.sortSentence(input1);
    cout << "Input: \"" << input1 << "\"\nOutput: \"" << output1 << "\"\n";

    // Test case 2
    string input2 = "is2 sentence4 This1 a3";
    string output2 = solution.sortSentence(input2);
    cout << "Input: \"" << input2 << "\"\nOutput: \"" << output2 << "\"\n";

    return 0;
}

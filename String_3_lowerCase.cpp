#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        string lowerCase;
        for(int i = 0; i < s.size(); i++) {
            lowerCase.push_back(tolower(s[i]));
        }
        return lowerCase;
    }
};

int main() {
    Solution solution;
    string input;

    // Prompt the user to enter a string
    cout << "Enter a string: ";
    getline(cin, input);

    // Convert the string to lowercase using toLowerCase function
    string result = solution.toLowerCase(input);

    // Output the result
    cout << "Lowercase string: " << result << endl;

    return 0;
}

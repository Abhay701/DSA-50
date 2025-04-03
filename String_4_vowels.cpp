#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        bool check = false;
        string a, b;
        int aCount = 0, bCount = 0;

        // Split the string into two halves
        for(int i = 0; i < s.size() / 2; i++) {
            a.push_back(s[i]);
        }
        for(int i = s.size() / 2; i < s.size(); i++) {
            b.push_back(s[i]);
        }

        // Count vowels in the first half
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ||
               a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U') {
                aCount++;
            }
        }

        // Count vowels in the second half
        for(int i = 0; i < b.size(); i++) {
            if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u' ||
               b[i] == 'A' || b[i] == 'E' || b[i] == 'I' || b[i] == 'O' || b[i] == 'U') {
                bCount++;
            }
        }

        // Check if vowel counts are the same
        if(aCount == bCount) {
            check = true;
        }
        return check;
    }
};

int main() {
    Solution solution;
    string input;

    // Prompt the user to enter a string
    cout << "Enter a string: ";
    getline(cin, input);

    // Check if halves are alike
    bool result = solution.halvesAreAlike(input);

    // Output the result
    if (result) {
        cout << "The two halves are alike (have the same number of vowels)." << endl;
    } else {
        cout << "The two halves are not alike (different number of vowels)." << endl;
    }

    return 0;
}

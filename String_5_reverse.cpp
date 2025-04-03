#include <iostream>
#include <string>
using namespace std;

string reverseString(string str) {
    string s;
    for(int i = (str.size() - 1); i >= 0; i--) {
        s.push_back(str[i]);
    }
    return s; // Return the reversed string
}

int main() {
    string input;

    // Prompt the user to enter a string
    cout << "Enter a string: ";
    getline(cin, input);

    // Reverse the string
    string reversed = reverseString(input);

    // Output the result
    cout << "Reversed string: " << reversed << endl;

    return 0;
}

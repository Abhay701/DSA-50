#include <iostream>
#include <string>
using namespace std;

void reverseHelper(string &str, int left, int right) {
    // Base case: when pointers cross, we're done
    if (left >= right) return;

    // Swap characters at 'left' and 'right' positions
    swap(str[left], str[right]);

    // Recursive call with narrowed bounds
    reverseHelper(str, left + 1, right - 1);
}

string reverseString(string str) {
    reverseHelper(str, 0, str.size() - 1);
    return str;
}

int main() {
    // Sample input string
    string str = "Hello, World!";
    
    // Print the original string
    cout << "Original string: " << str << endl;
    
    // Reverse the string
    string reversedStr = reverseString(str);
    
    // Print the reversed string
    cout << "Reversed string: " << reversedStr << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int occursOnce(vector<int> &a, int n) {
    int alone = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        if (count != 2) {  // If count is not 2, we found the unique element
            alone = a[i];
            break;
        }
    }
    return alone;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = occursOnce(a, n);
    cout << "The element that occurs only once is: " << result << endl;

    return 0;
}

#include <iostream>
using namespace std; 

void moveZerosToLeft(int *arr, int n) {
    int j = n - 1;  // Pointer to place non-zero elements starting from the right

    // Traverse the array backwards and shift non-zero elements to the right
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            arr[j] = arr[i];
            j--;
        }
    }
    cout<<"j = "<<j<<endl;

    // Fill the remaining positions with zeros
    // while (j >= 0) {
    //     arr[j] = 0;
    //     j--;
    // }

    // or

    // Fill the remaining positions with zeros
    for (int i = 0; i <= j; i++)
    {
        arr[i] = 0;
    }
    

    // Print the modified array
    cout << "Array after moving zeros to the left:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {2, 5, 0, 4, 6, 0, 8, 0, 9};
    int s = sizeof(a) / sizeof(a[0]);
    moveZerosToLeft(a, s);
    return 0;
}

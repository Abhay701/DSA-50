#include <iostream> // For input/output
#include <cmath>    // For pow()

using namespace std; // Use the standard namespace

// Node class definition
class Node {
public:
    int data; // Store binary digit (0 or 1)
    Node *next; // Pointer to the next node

    Node(int val) : data(val), next(NULL) {} // Constructor to initialize node
};

// Function to convert binary linked list to integer
int binaryToInteger(int n, Node *head) {
    int decimal = 0;
    int index = 0; // To keep track of the current bit position (rightmost = 0)

    // Traverse the linked list
    Node *temp = head;
    while (temp != NULL) {
        // Calculate decimal value by shifting bits and adding current bit value
        decimal += temp->data * pow(2, n - index - 1); // Use (n - index - 1) for correct power
        temp = temp->next; // Move to the next node
        index++; // Increment index
    }

    return decimal; // Return the calculated decimal value
}

// Function to print the linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data; // Print the current node's data
        if (temp->next != NULL) {
            cout << " -> "; // Print arrow if there is a next node
        }
        temp = temp->next; // Move to the next node
    }
    cout << endl; // Print a new line at the end
}

// Sample main function to test
int main() {
    // Creating a binary linked list representing the binary number 1011
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);

    cout << "Binary Linked List: ";
    printList(head);  // Print the binary linked list

    // Calculate the length of the linked list to pass it to binaryToInteger
    Node *temp = head;
    int length = 0;
    while (temp != NULL) {
        length++; // Count nodes in the list
        temp = temp->next; // Move to the next node
    }

    // Convert binary to decimal
    int decimalValue = binaryToInteger(length, head);
    cout << "Decimal Value: " << decimalValue << endl; // Print the decimal value

    // Free allocated memory (cleanup)
    temp = head;
    while (temp != NULL) {
        Node *nextNode = temp->next; // Store the next node
        delete temp; // Delete current node
        temp = nextNode; // Move to the next node
    }

    return 0; // Indicate successful execution
}

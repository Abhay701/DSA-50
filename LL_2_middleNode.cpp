#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node(int v) {
        value = v;
        next = NULL;
    }
};

// Function to traverse and print the linked list
void traverse(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to find the middle node of the linked list
Node *findMiddle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}

int main() {
    // Create linked list: 1->2->3->4->5->NULL
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List:" << endl;
    traverse(head);

    // Find and print the middle node
    Node *middle = findMiddle(head);
    if (middle != NULL) {
        cout << "The middle node value is: " << middle->value << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    // Clean up memory
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

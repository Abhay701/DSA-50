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

// Include the deleteNode function (as provided in the previous response)
Node *deleteNode(Node *head, int pos) {
    if (head == NULL) {
        return head; // Return NULL if the list is empty
    }

    if (pos == 0) {
        Node *h = head;
        head = head->next;
        delete h;
        return head;
    }

    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (pos >= count) {
        return head; // Return head unchanged if pos is out of bounds
    }

    Node *tempp = head;
    int i = 1;
    while (i < pos) {
        tempp = tempp->next;
        i++;
    }

    Node *deleteNode = tempp->next;
    tempp->next = deleteNode->next;
    delete deleteNode;
    return head;
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

    // Delete node at position 2 (0-indexed, so deletes the third node)
    int pos = 2;
    head = deleteNode(head, pos);

    cout << "List after deleting node at position " << pos << ":" << endl;
    traverse(head);

    // Clean up memory
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

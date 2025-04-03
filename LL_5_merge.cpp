#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// Your sortTwoLists function goes here

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    // If either of the lists is empty, return the other list
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }

    Node<int>* mergedHead = NULL;
    Node<int>* mergedTail = NULL;

    // Merge the two sorted lists
    while (first != NULL && second != NULL) {
        Node<int>* newNode = NULL;

        // Compare data from both lists and create a new node with the smaller value
        if (first->data <= second->data) {
            newNode = new Node<int>(first->data);
            first = first->next;  // Move to the next node in the first list
        } else {
            newNode = new Node<int>(second->data);
            second = second->next;  // Move to the next node in the second list
        }

        // If mergedHead is null, this is the first node to add
        if (mergedHead == NULL) {
            mergedHead = newNode;
            mergedTail = mergedHead;  // Set mergedTail to the first node
        } else {
            mergedTail->next = newNode;
            mergedTail = mergedTail->next;  // Move mergedTail to the new node
        }
    }

    // If there are remaining nodes in either list, append them
    while (first != NULL) {
        Node<int>* newNode = new Node<int>(first->data);
        mergedTail->next = newNode;
        mergedTail = mergedTail->next;
        first = first->next;
    }

    while (second != NULL) {
        Node<int>* newNode = new Node<int>(second->data);
        mergedTail->next = newNode;
        mergedTail = mergedTail->next;
        second = second->next;
    }

    return mergedHead;  // Return the head of the merged list
}


int main() {
    // Manually creating two sorted linked lists
    Node<int>* list1 = new Node<int>(1);
    list1->next = new Node<int>(3);
    list1->next->next = new Node<int>(5);

    Node<int>* list2 = new Node<int>(2);
    list2->next = new Node<int>(4);
    list2->next->next = new Node<int>(6);

    // Merge the two lists
    Node<int>* mergedList = sortTwoLists(list1, list2);

    // Print the merged list
    Node<int>* temp = mergedList;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory
    delete mergedList;

    return 0;
}

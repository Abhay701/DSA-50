#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list node.
template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to create a linked list from a vector
LinkedListNode<int>* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    LinkedListNode<int>* head = new LinkedListNode<int>(vals[0]);
    LinkedListNode<int>* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new LinkedListNode<int>(vals[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printList(LinkedListNode<int>* head) {
    LinkedListNode<int>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(LinkedListNode<int>* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // A list with 0 or 1 node is a palindrome
    }

    // Step 1: Find the middle of the linked list
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;      // Move slow by 1
        fast = fast->next->next; // Move fast by 2
    }

    // Step 2: Reverse the second half of the linked list
    LinkedListNode<int>* prev = nullptr;
    LinkedListNode<int>* current = slow;
    while (current != nullptr) {
        LinkedListNode<int>* nextNode = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current; // Move prev to current
        current = nextNode; // Move to next node
    }

    // Step 3: Compare the first half and the reversed second half
    LinkedListNode<int>* firstHalf = head;
    LinkedListNode<int>* secondHalf = prev; // This is the head of the reversed second half

    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false; // If mismatch found, it's not a palindrome
        }
        firstHalf = firstHalf->next; // Move to next node in the first half
        secondHalf = secondHalf->next; // Move to next node in the second half
    }

    return true; // If all matched, it's a palindrome
}

int main() {
    // Create a linked list from a vector and check if it's a palindrome
    vector<int> vals = {1, 2, 3, 2, 1};
    LinkedListNode<int>* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// LinkedListNode class definition
template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to check if the linked list is a palindrome
bool isPalindrome(LinkedListNode<int> *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    vector<int> v;
    LinkedListNode<int> *temp = head;
    while (temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0;
    int j = v.size() - 1;

    while (i <= j) {
        if (v[i] != v[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Function to create a linked list from a vector
LinkedListNode<int>* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    LinkedListNode<int>* head = new LinkedListNode<int>(values[0]);
    LinkedListNode<int>* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new LinkedListNode<int>(values[i]);
        current = current->next;
    }

    return head;
}

// Main function to test isPalindrome
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    vector<int> values1 = {1, 2, 3, 2, 1};
    LinkedListNode<int>* head1 = createLinkedList(values1);
    cout << "Is the linked list 1->2->3->2->1 a palindrome? " 
         << (isPalindrome(head1) ? "Yes" : "No") << endl;

    // Create a linked list: 1 -> 2 -> 3 -> 4
    vector<int> values2 = {1, 2, 3, 4};
    LinkedListNode<int>* head2 = createLinkedList(values2);
    cout << "Is the linked list 1->2->3->4 a palindrome? " 
         << (isPalindrome(head2) ? "Yes" : "No") << endl;

    // Clean up memory (optional, not shown in this code)
    // You may want to implement a function to delete the linked list nodes

    return 0;
}

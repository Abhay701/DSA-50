#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to remove nodes with data == k
Node *removeNodes(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    // Remove leading nodes with data == k
    while (head != NULL && head->data == k)
    {
        Node *deleteNode = head;
        head = head->next; // Move head to the next node
        delete deleteNode; // Delete the old head
    }

    Node *temp = head;

    // Remove remaining nodes with data == k
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == k)
        {
            Node *deleteNode = temp->next;
            temp->next = deleteNode->next; // Bypass the node to be deleted
            delete deleteNode;             // Delete the node
        }
        else
        {
            temp = temp->next; // Only move temp when we don't delete a node
        }
    }

    return head;
}

// Helper function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a simple linked list: 1 -> 2 -> 3 -> 4 -> 2 -> 5 -> 2
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(2);

    cout << "Original list: ";
    printList(head);

    // Remove nodes with data == 2
    int k = 2;
    head = removeNodes(head, k);

    cout << "List after removing nodes with value " << k << ": ";
    printList(head);

    return 0;
}

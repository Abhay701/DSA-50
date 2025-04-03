#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Function to remove duplicates from the linked list
Node *removeDuplicates(Node *head)
{
    Node *temp = head; // Pointer to traverse the linked list from the start

    // Outer loop traverses each node in the list
    while (temp != NULL)
    {
        Node *current = temp; // Pointer to check subsequent nodes for duplicates

        // Inner loop checks for duplicates after the `temp` node
        while (current->next != NULL)
        {
            // If a duplicate is found
            if (current->next->data == temp->data)
            {
                Node *deleteNode = current->next; // Node to be deleted
                current->next = deleteNode->next; // Remove the duplicate node from the list
                delete deleteNode;                // Free the memory of the duplicate node
            }
            else
            {
                current = current->next; // Move to the next node only if no deletion occurred
            }
        }

        // Move to the next distinct node in the list
        temp = temp->next;
    }

    return head; // Return the updated list with duplicates removed
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Sample main function to test
int main()
{
    // Creating a linked list with duplicates
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head); // Print the original list

    head = removeDuplicates(head); // Remove duplicates from the list

    cout << "List after removing duplicates: ";
    printList(head); // Print the updated list

    // Free memory (not shown, but recommended)
    // This would involve traversing the list again and deleting each node

    return 0; // Indicate successful execution
}

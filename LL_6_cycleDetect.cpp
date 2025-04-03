#include <iostream>
using namespace std;

// Define the Node class
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

// Function to detect a cycle in a linked list
bool detectCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // Move slow pointer by one step
        fast = fast->next->next; // Move fast pointer by two steps

        if (slow == fast)
        { // If slow meets fast, there is a cycle
            return true;
        }
    }

    return false; // If fast reaches NULL, there is no cycle
}

int main()
{
    // Create linked list 1 -> 2 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Manually create a cycle by pointing the last node's next to the second node
    head->next->next->next->next = head->next; // Creates a cycle: 1 -> 2 -> 3 -> 4 -> 2 ...

    // Detect cycle in the list
    if (detectCycle(head))
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }

    // Free memory (note: this may not work properly if there's a cycle)
    delete head;

    return 0;
}

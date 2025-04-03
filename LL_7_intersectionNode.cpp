#include <iostream>
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

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *h1 = firstHead;
    Node *h2 = secondHead;
    int len1 = 0, len2 = 0;

    // Calculate the length of both lists
    while (h1 != NULL)
    {
        h1 = h1->next;
        len1++;
    }
    while (h2 != NULL)
    {
        h2 = h2->next;
        len2++;
    }

    Node *head1 = firstHead;
    Node *head2 = secondHead;

    // Adjust the longer list to match the shorter one
    if (len1 <= len2)
    {
        int s = len2 - len1;
        for (int i = 1; i <= s; i++)
        {
            head2 = head2->next;
        }
    }
    else
    {
        int s = len1 - len2;
        for (int i = 1; i <= s; i++)
        {
            head1 = head1->next;
        }
    }

    // Traverse both lists and find the intersection
    while (head1 != NULL)
    {
        if (head1 == head2)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection found
}

// Function to create a new node
Node *createNode(int data)
{
    return new Node(data);
}

int main()
{
    // Create first linked list
    Node *head1 = createNode(4);
    head1->next = createNode(1);
    Node *intersection = createNode(8); // Intersection node
    head1->next->next = intersection;
    intersection->next = createNode(4);
    intersection->next->next = createNode(5);

    // Create second linked list
    Node *head2 = createNode(5);
    head2->next = createNode(6);
    head2->next->next = createNode(1);
    head2->next->next->next = intersection;

    // Find intersection
    Node *intersectionNode = findIntersection(head1, head2);

    // Print result
    if (intersectionNode != NULL)
    {
        cout << "Intersection at node with data: " << intersectionNode->data << endl;
    }
    else
    {
        cout << "No intersection" << endl;
    }

    return 0;
}

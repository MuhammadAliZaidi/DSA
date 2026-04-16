#include <iostream>
using namespace std;

// Node structure for Doubly Circular Linked List
struct Node
{
    Node* prev;   // points to previous node
    int data;     // stores value
    Node* next;   // points to next node
};

// Global head pointer
Node* head = NULL;

// Function to create doubly circular linked list from array
void create(int A[], int n)
{
    Node *t, *last;
    int i;

    // Create first node
    head = new Node;
    head->data = A[0];

    // Since only one node exists,
    // next and prev both point to itself
    head->next = head;
    head->prev = head;

    // last keeps track of the last node
    last = head;

    // Create remaining nodes
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];

        // New node points forward to head
        t->next = head;

        // New node points backward to last node
        t->prev = last;

        // Old last node points to new node
        last->next = t;

        // Head's previous points to new last node
        head->prev = t;

        // Move last pointer to new node
        last = t;
    }
}

// Function to display circular list
void display()
{
    Node* p = head;

    // If list is empty
    if (head == NULL)
        return;

    do
    {
        cout << p->data << " ";
        p = p->next;
    }
    while (p != head);

    cout << endl;
}

// Main function
int main()
{
    int A[] = {10, 20, 30, 40};

    create(A, 4);

    cout << "Doubly Circular Linked List: ";
    display();

    return 0;
}

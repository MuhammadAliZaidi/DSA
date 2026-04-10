#include <iostream>
using namespace std;

struct Node
{
    Node* prev;
    int data;
    Node* next;
} *first = NULL;

void create(int A[], int n)
{
    Node *t, *last;
    int i;

    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(Node* p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);

    cout << "Doubly Linked List: ";
    display(first);

    return 0;
}

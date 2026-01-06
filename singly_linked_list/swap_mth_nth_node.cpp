#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

Node *first = NULL;
Node *temp, *ttemp;

void add_element(int x, Node* &first)
{
    if(first == NULL)
    {
        first = new Node();
        first->data = x;
        first->next = NULL;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
            temp = temp->next;

        ttemp = new Node();
        ttemp->data = x;
        ttemp->next = NULL;
        temp->next = ttemp;
    }
}

void display(Node* &first)
{
    temp = first;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* -------- SWAP m-th AND n-th NODES -------- */
void swap_m_n(int m, int n, Node* &first)
{
    if(m == n)
        return;

    Node *prevM = NULL, *currM = first;
    Node *prevN = NULL, *currN = first;

    int i;

    // Find m-th node
    for(i = 1; i < m && currM != NULL; i++)
    {
        prevM = currM;
        currM = currM->next;
    }

    // Find n-th node
    for(i = 1; i < n && currN != NULL; i++)
    {
        prevN = currN;
        currN = currN->next;
    }

    // If m or n is out of range
    if(currM == NULL || currN == NULL)
        return;

    // Update previous pointers
    if(prevM != NULL)
        prevM->next = currN;
    else
        first = currN;

    if(prevN != NULL)
        prevN->next = currM;
    else
        first = currM;

    // Swap next pointers
    Node* tempNext = currM->next;
    currM->next = currN->next;
    currN->next = tempNext;
}

int main()
{
    add_element(7, first);
    add_element(8, first);
    add_element(9, first);
    add_element(10, first);
    add_element(11, first);
    add_element(12, first);

    cout << "Original list: ";
    display(first);

    swap_m_n(2, 5, first);

    cout << "After swapping 2nd and 5th nodes: ";
    display(first);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
};
Node *first=NULL,*temp,*ttemp;
void add_node(int x,Node* &first)
{
    if(first==NULL)
    {
        first=new Node();
        first->data=x;
        first->next=NULL;
        first->prev=NULL;
    }
    else
    {
        temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        ttemp=new Node();
        ttemp->data=x;
        ttemp->next=NULL;
        ttemp->prev=temp;
        temp->next=ttemp;
    }
}
void add_after_data(int x,int y,Node* &first)
{
    temp=first;
    while(temp->data!=x)
    {
        temp=temp->next;
    }
    Node *p=new Node();
    p->data=y;
    p->next=temp->next;
    p->prev=temp;
    temp->next->prev=p;
    temp->next=p;
}
void display(Node* &first)
{
    temp=first;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    add_node(5,first);
    add_node(6,first);
    add_node(7,first);
    add_node(8,first);
    add_node(9,first);
    add_node(10,first);
    cout<<"Doubly Linked List:";
    display(first);
    add_after_data(7,11,first);
    cout<<"Doubly Linked List:";
    display(first);
    return 0;
}
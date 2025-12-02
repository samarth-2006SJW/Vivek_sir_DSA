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
void delete_before_node(int x,Node* &first)
{
    temp=first;
    while(temp->data!=x)
    {
       temp=temp->next;
    }   
    ttemp=temp->prev;
    ttemp->prev->next=ttemp->next;
    ttemp->next->prev=ttemp->prev;
    ttemp->prev=NULL;
    ttemp->next=NULL;
    delete ttemp;
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    add_node(5,first);
    add_node(6,first);
    add_node(7,first);
    add_node(8,first);
    add_node(9,first);
    add_node(10,first);
    cout<<"Doubly Linked List:";
    display(first);
    delete_before_node(9,first);
    cout<<"Doubly Linked List after deletion:";
    display(first);

    return 0;
}    

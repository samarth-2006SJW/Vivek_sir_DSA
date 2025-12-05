#include<bits/stdc++.h>
using namespace std;
class Node{
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
    else{
        temp=first;
        while(temp->next!=NULL)
         temp=temp->next;
        ttemp=new Node();
        ttemp->data=x;
        ttemp->next=NULL;
        ttemp->prev=temp;
        temp->next=ttemp; 
    }
}    
void swap_F_S(Node* &first)
{
        temp=first->next;
        first->prev=temp;
        temp->prev=NULL;
        first->next=temp->next;
        temp->next->prev=first;
        temp->next=first;
        first=temp;
        
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
    swap_F_S(first);
    cout<<"Doubly Linked List:";
    display(first);
    return 0;
}

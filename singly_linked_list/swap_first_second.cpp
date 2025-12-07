#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
     int data;
     Node *next;
};
Node *first=NULL,*temp=NULL,*ttemp=NULL;
void add_node(int x,Node* &first)
{
    if(first==NULL)
    {
        first=new Node();
        first->data=x;
        first->next=NULL;
    }
    else
    {
    temp=first;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* p=new Node();
    p->data=x;
    p->next=NULL;
    temp->next=p;
    }
}
void swap_F_S(Node* &first)
{
    temp=first;
    ttemp=temp->next;
    temp->next=ttemp->next;
    ttemp->next=temp;
    first=ttemp;
}
void display( Node* &first)
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
    add_node(1,first);
    add_node(2,first);
    add_node(3,first);
    add_node(4,first);
    add_node(5,first);
    cout<<"Linked list:";
    display(first);
    swap_F_S(first);
    cout<<"Linked list after Swapping:";
    display(first);
    return 0;


}


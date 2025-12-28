#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
};
Node *first=NULL,*temp,*ttemp;
void add_element(int x,Node* &first)
{
    if(first==NULL)
    {
        first=new Node();
        first->data=x;
        first->next=first;
        first->prev=first;
    }
    else{
        temp=first->prev;
        ttemp=new Node();
        ttemp->data=x;
        ttemp->next=first;
        ttemp->prev=temp;
        temp->next=ttemp;
        first->prev=ttemp;  
    }
}
void add_after_node(int x,int y,Node* &first)
{
    temp=first;
    while(temp->data!=x)
     temp=temp->next;
    ttemp=new Node();
    ttemp->data=y;
    ttemp->next= temp->next;
    temp->next->prev=ttemp;
    temp->next=ttemp;
    ttemp->prev=temp;
}
void display(Node* &first)
{
    temp=first;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=first);
    cout<<endl;
}
int main()
{
    add_element(6,first);
    add_element(7,first);
    add_element(8,first);
    add_element(9,first);
    add_element(10,first);
    cout<<"Doubly Circular Linked List:";
    display(first);
    add_after_node(8,11,first);
    cout<<"Doubly Circular Linked List after addition:";
    display(first);
    return 0; 
   

}
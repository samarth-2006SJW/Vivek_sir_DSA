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
void swap_F_L(Node* &first)
{
    temp=first->prev;
    temp->next=first->next;
    first->next->prev=temp;
    first->next=temp;
    first->prev=temp->prev;
    temp->prev->next=first;
    first=temp;
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
    swap_F_L(first);
    cout<<"Doubly Circular Linked List after Swapping:";
    display(first);
    return 0; 
   

}
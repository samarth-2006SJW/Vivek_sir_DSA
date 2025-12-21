#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
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
    }
    else{
    temp=first;
    while(temp->next!=first)
     temp=temp->next;
    ttemp=new Node();
    ttemp->data=x;
    ttemp->next=first;
    temp->next=ttemp;
    } 
}
void delete_last_node(Node* &first)
{
    temp=first;
    while(temp->next!=first)
    {
     ttemp=temp;
     temp=temp->next;
    }
    ttemp->next=first;
    temp->next=NULL; 
    delete temp;
    
   
}
void display(Node* &first)
{
    temp=first;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp!=first);
    cout<<endl;
}
int main()
{
   
    add_element(7,first);
    add_element(8,first);
    add_element(9,first);
    add_element(10,first);
    add_element(11,first);
    add_element(12,first);

    cout<<"Singly Circular Linked List:";
    display(first);
    delete_last_node(first);
    cout<<"Singly Circular LL after deletion:";
    display(first);
    return 0;

}
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
Node *first=NULL;
Node *temp,*ttemp;
void add_element(int x, Node* &first)
{
    if(first==NULL)
    {

        first=new Node();
        first->data=x;
        first->next=NULL;
    }
    else{
    temp=first;
    while(temp->next!=NULL)
     temp=temp->next;
    ttemp=new Node();
    ttemp->data=x;
    ttemp->next=NULL;
    temp->next=ttemp;
    } 
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
    add_element(7,first);
    add_element(8,first);
    add_element(9,first);
    add_element(10,first);
    add_element(11,first);
    add_element(12,first);


    display(first);
    return 0;

}
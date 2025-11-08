#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *temp,*ttemp;
void add_element(int x,struct Node *first)
{
    temp=first;
    while(temp->next!=0)
     temp=temp->next;
    struct Node* p=new Node();
    p->data=x;
    p->next=NULL;
    temp->next=p; 
}
void delete_first_node(struct Node* &first)
{
    temp=first;
    first=first->next;
    temp->next=NULL;
    delete temp;
    
}
void display(struct Node* &first)
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
    struct Node* first=new Node();
    int x;
    cout<<"enter a elemnent:";cin>>x;
    first->data=x;
    first->next=NULL;
    add_element(7,first);
    add_element(8,first);
    add_element(9,first);
    add_element(10,first);
    add_element(11,first);
    add_element(12,first);

    cout<<"Linked list:";
    display(first);
    delete_first_node(first);
    cout<<"Linked list after deletion:";
    display(first);
    return 0;

}
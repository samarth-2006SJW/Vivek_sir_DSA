#include<bits/stdc++.h>
using namespace std;
struct Node{
    
    int data;
    struct Node *next;
};
struct Node *temp,*ttemp;
void add_element(int x,struct Node *first)
{
    temp=first;
    while(temp->next!=0)
     temp=temp->next;
    ttemp=new Node();
    ttemp->data=x;
    ttemp->next=NULL;
    temp->next=ttemp; 
}
void add_before_node(int x,int y,struct Node *first)
{
    temp=first;
    while(temp->data!=x)
        {
            ttemp=temp;
            temp=temp->next;
        }  
    struct Node* p=new Node();
    p->data=y;
    p->next=temp;
    ttemp->next=p;    

}
void display(struct Node* first)
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
    add_before_node(10,50,first);
    cout<<"Linked list after addition:";
    display(first);
    return 0;

}
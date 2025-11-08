#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
 Node *first=NULL;Node *temp,*ttemp;
void create_first(int x,Node* &first)
{
    first->data=x;
    first->next=NULL;
}
void display(Node* &first)
{
    temp=first;
    while(temp!=NULL){
     cout<<temp->data<<" ";   
     temp=temp->next;
    }  
    cout<< endl;
}
int main()
{
    Node* first=new Node();
    int x;
    cout<<"enter a elemnent:";cin>>x;
    create_first(x,first);
    
    display(first);
    
}
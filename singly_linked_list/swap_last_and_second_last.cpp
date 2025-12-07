#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
  int data;
  node *next;
};
node *first=NULL;node *temp,*ttemp;
void add_node(int x,node* &first){
  if(first==NULL)
  {
    first=new node();
    first->data=x;
    first->next=NULL;
  }
  else{  
  temp=first;
  while(temp->next!=NULL)
     temp=temp->next;
  ttemp=new node();
  ttemp->data=x;
  ttemp->next=NULL;
  temp->next=ttemp;
  }
}
void swap_L_SL(node* &first){
    temp = first;
    while(temp->next!= NULL){
        ttemp=temp;
        temp = temp->next;
    }
    node *p=first;
    while(p->next!=ttemp)
       p=p->next;
    temp->next=p->next;
    p->next=ttemp->next;
    ttemp->next=NULL; 
            
}


void display(node* &first)
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
    add_node(6,first);
    add_node(7,first);
    add_node(8,first);
    add_node(9,first);
    add_node(10,first);
    add_node(11,first);
    add_node(12,first);
    cout<<"Linked List:";
    display(first);
    swap_L_SL(first);
    cout<<"Linked List after Swapping:";
    display(first);
    return 0;  
}



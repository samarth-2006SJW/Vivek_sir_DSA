#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
Node *top=NULL,*temp,*ttemp;
void push(int x,Node* &top)
{
    ttemp=new Node();
    if(ttemp==NULL) return;
    ttemp->data=x;
    ttemp->next=top;
    top=ttemp;
}
int pop(Node* &top)
{
    if(top==NULL)
    {
        cout<<"Stack empty";
        return 0; 
    }
    else{
        int y;
        temp=top;
        y=temp->data;
        top=temp->next;
        delete temp;return y;
    }
}
int main()
{
    push(1,top);
    push(1,top);
    push(1,top);
    push(1,top);
    push(1,top);
    push(1,top);
}
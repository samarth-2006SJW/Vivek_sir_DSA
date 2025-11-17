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
bool isPalindrome(Node* first)
{
    vector<int> v;
    temp = first;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int n=v.size();
    for(int i=0;i<=n/2;i++)
     if(v[i]!=v[n-i-1])
      return false;
    return true;
}



int main()
{
    add_element(1,first);
    add_element(2,first);
    add_element(3,first);
    add_element(2,first);
    add_element(1,first);


    display(first);
    if(isPalindrome(first))
     cout<<"palindrome";
    else 
     cout<<"ain't palindromic"; 

    return 0;

}
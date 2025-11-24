#define SIZE 100
#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    int data[SIZE];
    int top;
};
Stack *p=NULL,s1;
void init(Stack* &p,Stack &s1)
{
    p=&s1;
    p->top=-1;
    return;
}
int empty(Stack* &p){
    if(p->top==-1)
     return 1;
    else
     return 0; 
}
int full(Stack* &p)
{
    if(p->top==SIZE-1)
     return 1;
    else return 0; 
}
void push(Stack* &p,int x)
{
    if(full(p)){
     std::cout<<"Stack overflow";
     return ;
    } 
    else
    {
        p->top++;
        p->data[p->top]=x;
    } 
}
int pop(Stack* &p)
{
    if(empty(p)){
      std::cout<<"Stack empty";
      return 0;
    }
    else{
       int y;
       y=p->data[p->top];
       p->top--;
       return y;

    } 

}
int main(){
    init(p,s1);
    push(p,1);
    push(p,2);
    push(p,3);
    push(p,4);
    push(p,5);
    std::cout<<"Stack:";
    for(int i=0;i<SIZE;i++)
    {
        int k=pop(p);
        if(k!=0)
        std::cout<<k<<" ";

    }

}


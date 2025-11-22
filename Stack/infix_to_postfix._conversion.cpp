#define SIZE 100
#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    char data[SIZE];
    int top;
};
Stack *p=NULL,s1;
void init(Stack* &p,Stack &s1)
{
    p=&s1;
    p->top=-1;
}
int empty(Stack* &p)
{
    if(p->top==-1)
    return 1;
    else return 0;

}
void push(Stack* &p,char op){
    p->top++;
    p->data[p->top]=op;
}
int pop(Stack* &p)
{
    if(empty(p)){
        cout<<"Stack Empty";
        return 0;
    }
    else{
        char y=p->data[p->top];
        p->top--;
        return y;
    }
}
int priority(char op)
{
    if(op=='{')
     return 0;
    else if(op=='+'||op=='-') 
     return 1;
    else if(op=='*'||op=='/') 
     return 2;
    else if(op=='^') 
     return 3;
    else return -1;
}
int priority_stack(Stack* &p)
{   
    if(p->data[p->top]=='{')
     return 0;
    else if(p->data[p->top]=='+'||p->data[p->top]=='-') 
     return 1;
    else if(p->data[p->top]=='*'||p->data[p->top]=='/') 
     return 2;
    else if(p->data[p->top]=='^') 
     return 3;
    else return -1;


}
void infix_to_postfix(char infix[],string &postfix){
    for(int i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i]))
        {
            postfix+=infix[i];
        }
        else if(priority(infix[i])==0){
            push(p,infix[i]);
        }
        else if(priority(infix[i])==1)
        {
             if(empty(p))
             push(p,infix[i]);
            else if(priority(infix[i])>priority_stack(p)){
                push(p,infix[i]);
            }
           
            else if(priority(infix[i])<priority_stack(p)||priority(infix[i])==priority_stack(p)) 
            {
                if(!empty(p))
                while(priority(infix[i])<priority_stack(p)||priority(infix[i])==priority_stack(p))
                  postfix+=pop(p);
                push(p,infix[i]);  
            }
        }
        else if(priority(infix[i])==2)
        {
            if(priority(infix[i])>priority_stack(p))
             push(p,infix[i]);
            else if(priority(infix[i])>priority_stack(p)||priority(infix[i])==priority_stack(p)) 
            {
                if(!empty(p))
                while(priority(infix[i])<priority_stack(p)||priority(infix[i])==priority_stack(p))
                  postfix+=pop(p);
                push(p,infix[i]);  
            }

        }
        else if(priority(infix[i])==3)
         push(p,infix[i]);
        else{
            while(p->data[p->top]!='{')
            {
                postfix+=pop(p);
            }
            pop(p);
        }  
       
    }
    if(!empty(p))
     while(p->top!=-1){
             postfix+=pop(p);
         }
    cout<<"Infix to Postfix:"<<postfix;

}
int main(){
    init(p,s1);
    char infix[SIZE];
    gets(infix);
    string postfix;
    infix_to_postfix(infix,postfix);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
#define SIZE 100
#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    char arr1[SIZE];
    string arr2[SIZE];
    int top1,top2;
};
Stack *p,s1;
void init(Stack* &p,Stack &s1){
    p=&s1;
    p->top1=-1;
    p->top2=-1;
}
int empty1(Stack* &p){
    if(p->top1==-1)
     return 1;
    else return 0;
}
int empty2(Stack* &p){
    if(p->top2==-1) return 1;
    else return 0;
}
int priority(char a){
    if(a=='{') return 0;
    else if(a=='+'||a=='-') return 1;
    else if(a=='*'||a=='/') return 2;
    else if(a=='^') return 3;
    else return -1;
}
int priority_stack(Stack* &p){
    if(p->top1==-1) return -1;
    if(p->arr1[p->top1]=='{')
     return 0;
    else if(p->arr1[p->top1]=='+'||p->arr1[p->top1]=='-') return 1;
    else if(p->arr1[p->top1]=='*'||p->arr1[p->top1]=='/') return 2;
    else if(p->arr1[p->top1]=='^') return 3;
    return -1; 
}
void push1(Stack* &p,char a){
    p->top1++;
    p->arr1[p->top1]=a;
}
void push2(Stack* &p,string a){
    p->top2++;
    p->arr2[p->top2]=a;
}
char pop1(Stack* &p){
    if(empty1(p)) return 0;
    else {
        char y=p->arr1[p->top1];
        p->top1--;
        return y;
    }
}
string pop2(Stack* &p){
    if(empty2(p)) return "";
    else{
        string str=p->arr2[p->top2];
        p->top2--;
        return str;
    }
}
void infix_to_prefix(Stack* &p,char infix[]){
    for(int i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            string k=string(1,infix[i]);
            push2(p,k);
        }
        else if(priority(infix[i])==0) push1(p,infix[i]);
        else if(priority(infix[i])==1){
            if(priority(infix[i])>priority_stack(p))
             push1(p,infix[i]);
            else if(priority(infix[i])<priority_stack(p)||priority(infix[i])==priority_stack(p))
            {
                while(priority(infix[i])<=priority_stack(p)){
                string str1=pop2(p);
                string str2=pop2(p);
                string str3=string(1,pop1(p));
                string str4=str2+str1;
                string str5=str3+str4;
                push2(p,str5);
                }
                push1(p,infix[i]);
            } 
        }  
        else if(priority(infix[i])==2){
            if(priority(infix[i])>priority_stack(p))
             push1(p,infix[i]);
            else if(priority(infix[i])<priority_stack(p)||priority(infix[i])==priority_stack(p))
            {
                while(priority(infix[i])<=priority_stack(p)){
                string str1=pop2(p);
                string str2=pop2(p);
                string str3=string(1,pop1(p));
                string str4=str2+str1;
                string str5=str3+str4;
                push2(p,str5);
                }
                push1(p,infix[i]);
            } 
        }
        else if(priority(infix[i])==3)
        {
            push1(p,infix[i]);
        }
        else {
            while(p->arr1[p->top1]!='{'){
                string str1=pop2(p);
                string str2=pop2(p);
                string str3=string(1,pop1(p));
                string str4=str2+str1;
                string str5=str3+str4;
                push2(p,str5);
            }
            pop1(p);
        }

    }
    if(!empty1(p)){
        while(p->top1!=-1){
            string str1=pop2(p);
            string str2=pop2(p);
            string str3=string(1,pop1(p));
            string str4=str2+str1;
            string str5=str3+str4;
            push2(p,str5);
        }
    }
    cout<<"Infix to Prefix:"<<pop2(p);
}
int main()
{
    init(p,s1);
    char infix[SIZE];
    cout<<"Enter Infix Expression:";//{a+b*c^{d/e^f}-g}
    cin.getline(infix, SIZE);
    infix_to_prefix(p,infix);
    return 0;
}
 
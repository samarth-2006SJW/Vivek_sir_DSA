#define SIZE 100
#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    string arr[SIZE];
    int top;
};
Stack *p,s1;
void init(Stack* &p,Stack &s1){
    p=&s1;
    p->top=-1;
}
int empty(Stack* &p){
    if(p->top==-1) return 1;
    else return 0;
}
void push(Stack* &p,string prefix){
    p->top++;
    p->arr[p->top]=prefix;
}
string pop(Stack* &p){
    if(empty(p)) return "";
    else{
        string str=p->arr[p->top];
        p->top--;
        return str;
    }
}
void postfix_to_prefix(Stack* &p,string postfix){
    for(int i=0;i<postfix.length();i++){
        if(isalnum(postfix[i])){
            string str=string(1,postfix[i]);
            push(p,str);
        }
        else{
            string str1=pop(p);
            string str2=pop(p);
            string str3=string(1,postfix[i]);
            string str4=str3+str2+str1;
            push(p,str4);
        }
    }
    cout<<"Postfix to Prefix:"<<pop(p);
}
int main(){
    init(p,s1);
    string postfix;
    cout<<"Enter Postfix Expression:";
    getline(cin,postfix);
    postfix_to_prefix(p,postfix);
    return 0;
}

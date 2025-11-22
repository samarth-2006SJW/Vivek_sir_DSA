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
void push(Stack* &p,string postfix){
    p->top++;
    p->arr[p->top]=postfix;
}
string pop(Stack* &p){
    if(empty(p)) return "";
    else{
        string str=p->arr[p->top];
        p->top--;
        return str;
    }
}
int calculate(int o1,int o2,string op){
    if(op=="+") return o1+o2;
    else if(op=="-") return o1-o2;
    else if(op=="*") return o1*o2;
    else if(op=="/") return o1/o2;
    else if(op=="^") return (int)pow(o1,o2);
    else return -1;
}
int prefix_eval(Stack* &p,string prefix){
    reverse(prefix.begin(),prefix.end());
    for(int i=0;i<prefix.length();i++){
        if(isalnum(prefix[i]))
        {
            string str=string(1,prefix[i]);
            push(p,str);
        }
        else{
            int o1=stoi(pop(p));
            int o2=stoi(pop(p));//stoi ek function hai jo string ko int main convert karta hai
            string str=string(1,prefix[i]);
            int r=calculate(o1,o2,str);
            string str1=to_string(r);// ye digit ko string banayega jaise 12 diya number to "12" string milega
            push(p,str1);
        }
    }
    int z=stoi(pop(p));
    return z;
}
int main(){
    init(p,s1);
    string prefix;cout<<"Enter Prefix Numeric Expression:";
    getline(cin,prefix);
    int z=prefix_eval(p,prefix);
    cout<<"Final Value of Expression="<<z;
    return 0;
}
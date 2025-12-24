#include<bits/stdc++.h>
#define SIZE 100
using namespace std;
class Queue{
    public:
    int data[SIZE];
    int front;int rear;
};
Queue *p=NULL,s1;
void init(Queue* &p,Queue &s1){
    p=&s1;
    p->front=-1;
    p->rear=-1;
}
int empty(Queue* &p){
    if(p->front==-1)
      return 1;
    else return 0;
}
int full(Queue*&p){
    if(p->rear==SIZE-1)
      return 1;
    else return 0;  
}
void enqueue(Queue* &p,int x){
    if(full(p)==1){
     cout<<"Queue is full"<<endl;;
     return;
    } 
    else{
        if(p->front==-1){p->front=0;}
        p->rear++;
        p->data[p->rear]=x;
        return;
    }
}
int dequeue(Queue* &p){
    if(empty(p)){
        cout<<"Empty queue!";return -1;
    }
    else{
        if(p->front==p->rear){
            int y;
            y=p->data[p->front];
            p->front=p->rear=-1;
            return y;
        }
        else{
            int y;
            y=p->data[p->front];
            p->front++;
            return y;
        }
    }
}
int main(){
    init(p,s1);
    enqueue(p,1);
    enqueue(p,2);
    enqueue(p,3);
    enqueue(p,4);
    enqueue(p,5);
    enqueue(p,6);
    enqueue(p,7);
    enqueue(p,8);
    enqueue(p,9);
    enqueue(p,10);
    cout<<"Queue:";
    int count=p->rear-p->front+1;
    for(int i=0;i<count;i++){
        int k=dequeue(p);
        cout<<k<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class LQueue{
    public:
    int data;
    LQueue *next;
};
LQueue *front=NULL,*rear=NULL,*temp,*ttemp;
void enqueue(LQueue* &front,LQueue* &rear,int x){
    if(front==NULL){
        temp=new LQueue;
        temp->data=x;
        temp->next=NULL;
        front=rear=temp;

    }
    else{
    temp=rear;
    ttemp=new LQueue();
    if(ttemp==NULL) return;
    rear=ttemp;
    ttemp->data=x;
    temp->next=ttemp;
    ttemp->next=NULL;
    rear=ttemp;
    }
}; 
int dequeue(LQueue* &front,LQueue* &rear){
    if(front==NULL)
    {
        cout<<"Queue Empty";
        return 0;    
    }
    else{
        if(front==NULL)
         return -1;
        else if(front==rear){
        int y=front->data;
        delete front;
        front=rear=NULL;
        return y;
        }
        else{
             temp=front;
             front=front->next;
             int y=temp->data;
             temp->next=NULL;
             delete temp;
             return y;
        } 
    }
}

int main(){
    enqueue(front,rear,1);
    enqueue(front,rear,2);
    enqueue(front,rear,3);
    enqueue(front,rear,4);
    enqueue(front,rear,5);
    enqueue(front,rear,6);
    enqueue(front,rear,7);
    enqueue(front,rear,8);
    enqueue(front,rear,9);
    enqueue(front,rear,10);
    cout<<"Queue:";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";



}

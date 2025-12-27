#include<bits/stdc++.h>
using namespace std;
class BST{
    public:
    BST* left;
    int data;
    BST* right;
};
BST *root=NULL,*temp,*ttemp;
void add_node(BST* &root,int x){
    if(root==NULL){
        root=new BST();
        root->data=x;
        root->left=root->right=NULL;
    }
    else{
        temp=root;
        while(temp!=NULL){
            ttemp=temp;
            if(temp->data>x)
             temp=temp->left;
            else temp=temp->right; 
        }
        BST* p=new BST();
        p->data=x;
        p->left=p->right=NULL;
        if(ttemp->data>x)
         ttemp->left=p;
        else ttemp->right=p; 
    }
}
void Inorder_traversal(BST* P){
    if(P==NULL)
     return;
    else 
    {
        Inorder_traversal(P->left);
        cout<<P->data<<" ";
        Inorder_traversal(P->right);
    }
}
int level_node(BST *P,int x,int level)
{
    if(P==NULL) return -1;
    if(P->data==x)
      return level;
    else{
         level_node(P->left,x,level+1);
         level_node(P->right,x,level+1);
     } 
}
int main(){
    add_node(root,50);
    add_node(root,30);
    add_node(root,70);
    add_node(root,90);
    add_node(root,20);
    add_node(root,10);
    add_node(root,100);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    // add_node(root,50);
    Inorder_traversal(root);
    int level=0;
    int k=level_node(root,70,level);
    cout<<"Level of a node:"<<k;
    return 0;
}
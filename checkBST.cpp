#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node *lc, *rc;
}node;

node *newNode(int x){
    node *ptr = new node;
    ptr->val = x;
    ptr->lc = NULL;
    ptr->rc = NULL;
    return ptr;
}

bool checkBST(node *root, node *l = NULL, node *r = NULL){
    if(root==NULL)
        return true;

    if(l!=NULL && l->val >= root->val)
        return false;

    if(r!=NULL && r->val <= root->val)
        return false;

    return (checkBST(root->lc, l, root) && checkBST(root->rc, root, r));            
}

int main(){
    node *root = newNode(2);
    root->lc = newNode(1);
    root->rc = newNode(3);
    
    if(checkBST(root, NULL, NULL))
        cout<<"YES, It's a BST\n";
    else
        cout<<"NO, It's not a BST\n";

    return 0;    
}
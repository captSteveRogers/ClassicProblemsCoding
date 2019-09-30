#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
} node;

node *newNode(int x){
    node *ptr = new node;
    ptr->val = x;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

bool isSymm(node *root){
    if(root==NULL)
        return true;
    if(!root->left && !root->right)
        return true;

    queue<node *> q;
    q.push(root);
    q.push(root);
    node *l,*r;
    while(!q.empty()){
        l = q.front();
        q.pop();
        r = q.front();
        q.pop();

        if(l->val != r->val)
            return false;

        if(l->left && r->right){
            q.push(l->left);
            q.push(r->right);
        }
        else if(l->left || r->right)
            return false;

        if(l->right && r->left){
            q.push(l->right);
            q.push(r->left);
        }
        else if(l->right || r->left)
            return false;        
    }
    return true;        
}

int main(){
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(4); 
    root->right->right = newNode(3); 
  
    if(isSymm(root)) 
        cout << "The given tree is Symmetric\n"; 
    else
        cout << "The given tree is not Symmetric\n"; 
    return 0; 
}
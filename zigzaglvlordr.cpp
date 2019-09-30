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

void zigzag(node *root){
    if(!root)
        return;

    // stack<node *> currlvl;
    // stack<node *> nxtlvl;
    // currlvl.push(root);
    // bool l2r = true;
    // while(!currlvl.empty()){
    //     node *temp = currlvl.top();
    //     currlvl.pop();
    //     if(temp){
    //         cout<<temp->val<<" ";
    //         if(l2r){
    //             if(temp->right)
    //                 nxtlvl.push(temp->left);
    //             if(temp->left)
    //                 nxtlvl.push(temp->right);    
    //         }
    //         else{
    //             if(temp->right)
    //                 nxtlvl.push(temp->right);
    //             if(temp->left)
    //                 nxtlvl.push(temp->left);    
    //         }
    //     }
    //     if(currlvl.empty()){
    //         l2r = !l2r;
    //         swap(currlvl, nxtlvl);
    //     }
    // } 

    queue<node *> q;
    q.push(root);
    int lvl = 1;
    while(!q.empty()){
            lvl++;
            int cnt = q.size();
            for(int i=0; i<cnt; i++){
                node *tmp = q.front();
                q.pop();
                if(tmp == NULL)
                    continue;
                cout<<tmp->val<<" ";
                if(lvl%2==0){
                    q.push(tmp->right);
                    q.push(tmp->left);
                }
                else{
                    q.push(tmp->left);
                    q.push(tmp->right);
                }    
            }
            cout<<endl;
        }   
}

int main(){
    node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    zigzag(root);
}
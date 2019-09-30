#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node *lc;
    struct node *rc;
} node;

node *newNode(int x){
    node *ptr = new node;
    ptr->val = x;
    ptr->lc = NULL;
    ptr->rc = NULL;
    return ptr;
}

void preorder(node *ptr){
    if(!ptr)
        return;

    cout<<ptr->val<<" ";
    preorder(ptr->lc);
    preorder(ptr->rc);    
}

vector<node *> createBst(int start, int end){
    vector<node *> list;
    if(start>end){
        list.push_back(NULL);
        return list;
    }

    for(int i=start; i<=end; i++){
        vector<node *> leftsub = createBst(start, i-1);
        vector<node *> rightsub = createBst(i+1, end);
        for(int j=0; j<leftsub.size(); j++){
            node *lt = leftsub[j];
            for(int k=0; k<rightsub.size(); k++){
                node *rt = rightsub[k];
                node *root = newNode(i);
                root->lc = lt;
                root->rc = rt;
                list.push_back(root);
            }
        }
    }
    return list;
}

int main(){
    vector<node *> trees = createBst(1,3);
    cout<<"Preorder Traversal of all constructed trees: \n";
    for(int i=0; i<trees.size();i++){
        preorder(trees[i]);
        cout<<endl;
    }
    return 0;
}
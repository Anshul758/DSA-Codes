#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
};

Node* newNode(int val) {
    Node *temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

void solve(Node *root) {
    if(root==NULL)
        return;
    
    queue<Node*> s;
    s.push(root);
    
    while(!s.empty()) {
        int size = s.size();
        vector<int>v;
        
        for(int i=0; i<size; i++) {
            Node *temp = s.front();
            s.pop();
            
            if(temp->left != NULL)
                s.push(temp->left);
            if(temp->right != NULL)
                s.push(temp->right);
            v.push_back(temp->val);
        }
        
        for(int i=0;i<v.size(); i++) {
            cout<<v[i]<<" ";
        }
    }
}

int main()
{
    Node *root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);
    
    solve(root);
    
    return 0;
}
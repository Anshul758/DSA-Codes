#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int val;
	struct Node *left, *right; 
};

Node* newNode(int val)
{
	Node *temp = new Node;
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

int max_height(Node *root)
{
	if(root == NULL)
		return 0;

	int lh = max_height(root->left);
	int rh = max_height(root->right);

	return 1+max(lh,rh);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);
    root->left->right->left->left = newNode(8);

    cout<<max_height(root);

    return 0;
}
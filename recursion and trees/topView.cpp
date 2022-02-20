#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node *left, *right;
};

Node* newNode(int val) {
	Node* temp = new Node;
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

void solve(Node *root, vector<int>& ans) {
	if(root == NULL)
		return;

	
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->right = newNode(7);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	vector<int> ans;
	solve(root, ans); 
}
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

int main()
{
	
}
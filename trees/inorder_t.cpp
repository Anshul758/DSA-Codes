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

void inorderD(Node *root) {
	stack<Node *> st;
	
	Node *temp = root;

	while(true)
	{
		if(temp != NULL) {
			st.push(temp);
			temp = temp->left;
		}

		else {
			if(st.empty()==true) break;

			temp = st.top();
			st.pop();
			cout<<temp->val<<" ";
			temp = temp->right;
		}
	}

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

	inorderD(root);

	return 0;
}
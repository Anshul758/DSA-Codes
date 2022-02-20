#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node *left, *right;
};

Node* newNode(int val) {
	Node *temp = new Node;
	temp->val = val;
	temp->right = temp->right = NULL;
	return temp;
}

int max_pathsum(Node *root, int &maxi)
{
	if(root==NULL){
		return 0;
	}

	int ls = max(0,max_pathsum(root->left, maxi));
	int rs = max(0,max_pathsum(root->right, maxi));

	maxi = max(maxi, ls+rs+root->val);

	return root->val + max(ls,rs);
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

    int maxi = INT_MIN;
    max_pathsum(root, maxi);
    cout<<maxi<<endl;
}
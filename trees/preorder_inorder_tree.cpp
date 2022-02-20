#include <bits/stdc++.h> 
// #include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
// using namespace __gnu_pbds;
// Policy based data structure 
// template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ll long long int
#define pii pair<ll,ll>
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define vi vector<ll>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdout);
#define gin(x) cerr<<#x<<" : "<<x<<" ";
#define fin cerr<<endl;
#define F first
#define S second
#define np next_permutation
#define inf 1e18
#define mod 1000000007
#define N 200009
#define PI 3.14159265358979323846
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
void sout(){
	cout<<endl;
}
template <typename T,typename... Types>
void sout(T var1,Types... var2){
	cout<<var1<<" ";
	sout(var2...);
}

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}

int search(int inorder[], int start, int end, int curr) {
	for(int i=start; i<=end; i++){
		if(inorder[i] == curr)
			return i;
	}
	return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end) {
	static int idx = 0;
	if(start > end) 
		return NULL;

	int curr = preorder[idx];
	idx++;

	Node* node = newNode(curr);
	if(start == end)
		return node;

	int pos = search(inorder, start, end, curr);
	node->left = buildTree(preorder, inorder, start, pos-1);
	node->right = buildTree(preorder, inorder, pos+1, end);

	return node;
}


void inorderPrint(Node* root) {
	if(root == NULL)
		return;
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);

	return;
}

void solve(){
	int preorder[] = {1,2,4,3,5};
	int inorder[] = {4,2,1,5,3};

	Node* root = buildTree(preorder, inorder, 0, 4);
	inorderPrint(root);

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}
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

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 


Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct Node* lca(struct Node* root, int n1, int n2) {
	if(root == NULL)
		return NULL;

	if(root->data == n1 || root->data == n2) 
		return root;

	Node* left_lca = lca(root->left, n1, n2);
	Node* right_lca = lca(root->right, n1, n2);

	if(left_lca && right_lca)
		return root;

	if(left_lca == NULL && right_lca == NULL)
		return NULL;

	return (left_lca != NULL)? left_lca : right_lca;
}

int height(struct Node* root, int k, int h) {
	if(root == NULL)
		return -1;

	if(root->data == k)
		return h;

	int left_h = height(root->left, k, h+1);
	
	if(left_h != -1)
		return left_h;

	return height(root->right, k, h+1);
}

int  shortest(struct Node* root, int n1, int n2) {
	Node* LCA = lca(root, n1, n2); 

	int d1 = height(LCA, n1, 0);
	int d2 = height(LCA, n2, 0);

	return d1+d2;
}

void solve(){
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->right = newNode(5); 

    int n1=4, n2=5;

    cout<<shortest(root, n1, n2);

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
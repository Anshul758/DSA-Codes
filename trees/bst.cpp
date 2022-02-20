#include <bits/stdc++.h> 
// #include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
// using namespace __gnu_pbds;
// Policy based data structure 
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
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

Node* newNode(int data) {
    Node *temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node* bst(int array[], int start, int end) {
	if(start > end)
		return NULL;

	int mid = (start + end) / 2;
	Node* root = newNode(array[mid]);

	root->left = bst(array, start, mid-1);
	root->right = bst(array, mid+1, end);

	return root;
}

void preorder(Node* root){
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

	return;
}


void solve(){
	int arr[] = {1,5,7,8,10,12};
	Node* root = bst(arr, 0, 6);

	preorder(root);

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t;
	// cin>>t;
	t=1;
	cout<<"Anshul Sharma"<<endl<<"19021011558"<<endl;
	while(t--){
		solve();
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}
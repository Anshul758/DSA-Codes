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
	struct Node* left, *right;
};

Node* newNode(int data) {
	Node *node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

int calcHeight(Node* root) {
	if(root == NULL)
		return 0;

	return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}

// complexity o(n^2)
int calcDiameter(Node* root) {
	if(root == NULL)
		return 0;

	int lHeight = calcHeight(root->left);
	int rHeight = calcHeight(root->right);

	int currDiameter = lHeight + rHeight+1;

	int lDiameter = calcDiameter(root->left);
	int rDiameter = calcDiameter(root->right);

	return max(currDiameter, max(lDiameter, rDiameter));
}

// optimized way by using pointer o(n)

int diameter(Node* root, int *height) {
	if(root == NULL){
		*height = 0;
		return 0;
	}

	int lh=0, rh=0;

	int lDiameter = diameter(root->left, &lh);
	int rDiameter = diameter(root->right, &rh);

	int currdia = lh+rh+1;
	*height = max(lh,rh)+1;

	return max(currdia, max(lDiameter, rDiameter));
}

void solve(){
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);

    int height = 0;
    cout<<diameter(root, &height);

    return;
}

int main()
{
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
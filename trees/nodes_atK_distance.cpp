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

void printSubtree(Node* root, int k) {
	if(root == NULL || k<0)
		return;

	if(k==0) {
		cout<<root->data<<" ";
		return;
	}

	printSubtree(root->left, k-1);
	printSubtree(root->right, k-1);

	return;
}

int printAtK(Node* root, Node* target, int k) {
	if(root == NULL)
		return -1;

	if(root == target){
		printSubtree(root, k);
		return 0;
	}

	int dl = printAtK(root->left, target, k);
	if(dl != -1) {
		if(dl + 1 == k) {
			cout<<root->data<<" ";
		} 
		else {
			printSubtree(root->right, k-dl-2);
		}
		return 1+dl;
    } 

    int dr = printAtK(root->right, target, k);
	if(dr != -1) {
		if(dr + 1 == k) {
			cout<<root->data<<" ";
		} 
		else {
			printSubtree(root->left, k-dr-2);
		}
		return 1+dr;
    }

    return -1; 
}


void solve(){
	Node * root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    Node * target = root->left->right;

	printAtK(root, target, 2);

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
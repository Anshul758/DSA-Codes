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

void correctBSTUtil(struct Node* root, struct Node** first, 
	struct Node** middle, struct Node** last, struct Node** prev)
{
	if(root) {
		correctBSTUtil(root->left, first, middle, last, prev);

		if(*prev && root->data < (*prev)->data) {
			if(!*first) {
				*first = *prev;
				*last = root;
			}

			else 
				*last = root;
		}

		*prev = root;

		correctBSTUtil(root->right, first, middle, last, prev);
	}
}

void correctBST( struct Node* root )
{
    struct Node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;

    correctBSTUtil( root, &first, &middle, &last, &prev );
  
    if( first && last )
        swap(first->data, last->data);
    else if( first && middle ) // Adjacent nodes swapped
        swap( first->data, middle->data);
  
    // else nodes have not been swapped, passed tree is really BST.
}

void printInorder(Node* root) {
	if(root == NULL)
		return;

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void solve(){
	struct Node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
  	printInorder(root);
  	cout<<endl;
  	correctBST(root);
  	printInorder(root);
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
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

vector<int> toConvert(Node* root, vector<int> v) {
        if(root == NULL)
            return v;
        toConvert(root->left);
        v.push_back(root->data);
        toConvert(root->right);
        
        return v;
    }
    
    Node* bstChange(vector<int> v, int start, int end) {
        if(start > end)
            return NULL;
        
        int mid = (start+end)/2;
        Node* root = newNode(v[mid]);
        
        root->left = bst(root->left, start, mid-1);
        root->right = bst(root->right, mid+1, end);
        
        return root;
    } 
        
    Node* bstToGst(Node* root) {
        vector<int> v;
        v = toConvert(root, v);
        
        for(int i=v.size()-2; i>=0; i--) {
            v[i] += v[i+1];
        }
        sort(v.beign(), v.end());
        
        root = bstChange(v, 0, v.size());
        
        return root;
    }

    void inorder(Node* root) {
    	if (root == NULL) return; 

    // Create an empty queue for 
    // level order tarversal 
    queue<Node *> q; 

    // Enqueue Root and initialize height 
    q.push(root); 

    while (q.empty() == false) 
    { 
        // Print front of queue and remove 
        // it from queue 
        Node *node = q.front(); 
        cout << node->data << " "; 
        q.pop(); 

        /* Enqueue left child */
        if (node->left != NULL) 
            q.push(node->left); 

        /* Enqueue right child */
        if (node->right != NULL) 
            q.push(node->right); 
    }
    }

void solve(){
	Node* root = newNode(4);
	root->left = newNode(1);
	root->right = newNode(6);
	root->left->left = newNode(0);
	root->left->right = newNode(2);
	root->left->right->right = newNode(3);
	root->right->left = newNode(5);
	root->right->right = newNode(7);
	root->right->right->right = newNode(8);

	root = bstToGst(root);
	inorder(root);
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
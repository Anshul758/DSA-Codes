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
	Node* left, *right;
};

Node* newNode(int data) {
	Node* root = new Node;
	root->data = data;
	root->left = root->right = NULL;

	return root;
}

int height(Node* root) {
    if(root == NULL)
        return 0;
        
    return max(height(root->left), height(root->right)) +1;
}
    
int find(Node* root, int h) {
    if(root == NULL)
        return 0;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int k = 1, ans;
        
    while(!q.empty()) 
    {
        Node* temp = q.front();
        q.pop();
            
        if(k == h) {
            if(temp->left) {
                ans = temp->left->data;
                break;
            }
            else if(temp->right) {
            	ans = temp->right->data;
            	break;
            }
        }
        
        if(temp) {
            if(temp->left) 
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else if(!q.empty()) {
            q.push(NULL);
            k++;
        }
    }
    return  ans;
}


void solve(){
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->left = newNode(7);

	int h = height(root);

	if(h == 1) {
		cout<< root->data;
	}
	else {
		cout<<find(root, h-1);
	}
	
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
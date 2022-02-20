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

int n,m;
vector<int> adj[N];

void Dfs(int node, vector<bool> &visited, stack<int> &st) {
	visited[node] = true;
	for(auto it: adj[node]) {
		if(!visited[it]) 
			Dfs(it,visited, st);
	}

	st.push(node);
}

void revDfs(int node, vector<bool> &visited, vector<int> transpose[]) {
	cout<<node<<" ";
	visited[node] = true;
	for(auto it: transpose[node]) {
		if(!visited[it])
			revDfs(it, visited, transpose);
	}
}

void solve(){
	cin>>n>>m;
	stack<int> mystack;

	rep(i,0,m) {
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}

	vector<bool> visited(n,false);
	rep(i,0,n) {
		if(!visited[i])
			Dfs(i,visited,mystack);
	}

	vector<int> transpose[n];

	rep(i,0,n) {
		visited[i] = false;
		for(auto it: adj[i])
			transpose[it].push_back(i);
	}

	while(!mystack.empty()) {
		int curr = mystack.top();
		mystack.pop();

		if(visited[curr] == false) {
			revDfs(curr,visited,transpose);
			cout<<"\n";
		}
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
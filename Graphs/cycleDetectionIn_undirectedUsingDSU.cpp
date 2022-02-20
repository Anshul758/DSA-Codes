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

vector<int> parent(N);
vector<int> size(N);

void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
}

int find_set(int a) {
	if(a == parent[a])
		return a;
	return parent[a] = find_set(parent[a]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b= find_set(b);

	if(a != b) {
		if(size[a] < size[b])
			swap(a,b);
		size[a] += size[b];
		parent[b] = a;
	}
	
}


void solve(){
	for(int i=0; i<N; i++) {
		make_set(i);
	}

	int n,m;
	cin>>n>>m;

	vector<vector<int>> edges;

	rep(i,0,m) {
		int x,y;
		cin>>x>>y;

		edges.push_back({x,y});
	}

	bool cycle = false;

	for(auto i:edges) {
		int u=i[0];
		int v=i[1];

		int x = find_set(u);
		int y= find_set(v);

		if(x==y)
			cycle =  true;
		else 
			union_set(u,v);
	}

	if(cycle)
		cout<<"Cycle present";
	else 
		cout<<"Cycle Not present";
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
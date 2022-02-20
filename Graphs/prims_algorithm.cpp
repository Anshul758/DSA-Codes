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
// #define inf 1e9
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

vector<vector<int>> g[N];
vector<bool> visited[N];
vector<int> dist[N], parent[N];
int cost = 0;

void primsMST(int source) {
	int inf = 1e9;
	for (int i = 1; i < n; ++i)
	{
		dist[i] = inf;
	}

	set<vector<int>> s;
	dist[source] = 0;
	s.insert({0, source});

	while(!s.empty()) {
		auto x = *(s.begin());
		s.erase(x);
		visited[x[1]] = true;
		int u = x[1];
		int v = parent[x[1]];
		int w = x[0];

		cost += w;

		for(auto it:g[x[1]]) {
			if(visited[it[0]])
				continue;
			if(dist[it[0]] > it[1]) {
				s.erase({dist[it[0]], it[0]});
				dist[it[0]] = it[1];
				s.insert({dist[it[1]], it[1]});
				parent[it[0]] = x[1];
			}
		}
	}
	cout<<cost;
}

void solve(){
	cin>>n>>m;

	rep(i,0,m) {
		int u,v,w; cin>>u>>v>>w;
		g[u].push_back({v.w});
		g[v].push_back({u,w});
	}

	primsMST(0);

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
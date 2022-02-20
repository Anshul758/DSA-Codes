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




void solve(){
	int n; cin>>n;
	vector<int> t;
	vector<string> s;

	for(int i=0; i<n; i++) {
		string b; cin>>b;
		int a; cin>>a;
		s.push_back(b);
		t.push_back(a);
	}

	// for(int i=0; i<n; i++) {
	// 	cout<<s[i]<<" "<<t[i]<<" ";
	// }

	int Max = INT_MIN, index;
	for(int i=0; i<n; i++){
		if(t[i] > Max)
			index = i;

		Max = max(Max, t[i]);
	}

	s.erase(s.begin()+index);
	t.erase(t.begin()+index);

	int mx = INT_MIN, idx;
	for(int i=0; i<n; i++){
		if(t[i] > mx)
			idx = i;

		mx = max(mx, t[i]);
	}
	
	cout<<s[idx]<<endl;

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
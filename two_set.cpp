// Your task is to divide the numbers 1,2,…,n into two sets of equal sum.

#include <bits/stdc++.h> 
// #include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
// using namespace __gnu_pbds;
// // Policy based data structure 
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
	ll n, sum=0;
	cin>>n;

	if(n*(n+1)/2%2) {
		cout<<"NO";
		return;
	}
	
	vector<int> v1, v2;
	int j=0;

	if(n%4) {
		j=3;
	}
	else {
		j=4;
	}

	for(int i=0; i<(n-1)/4; i++) {
		v1.push_back(4*i+1+j);
		v1.push_back(4*i+4+j);
		v2.push_back(4*i+2+j);
		v2.push_back(4*i+3+j);
	}

	if(n%4) {
		v1.push_back(1);
		v1.push_back(2);
		v2.push_back(3);
	} 
	else {
		v1.push_back(1);
		v1.push_back(4);
		v2.push_back(3);
		v2.push_back(2);
	}

	cout<<"YES\n";
	cout<<v1.size()<<"\n";
	for(int i:v1)
		cout<<i<<" ";
	cout<<"\n";

	cout<<v2.size()<<"\n";
	for(int i:v2)
		cout<<i<<" ";

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
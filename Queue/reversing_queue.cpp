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

void reverse(queue<int>& q, int x) {
	stack<int> s;

	if(q.size() == 0) 
		return;

	if(x<=0)
		return;

	for(int i=1; i<=x; i++) {
		s.push(q.front());
		q.pop();
	}

	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	for(int i=0; i<q.size()-x; i++) {
		q.push(q.front());
		q.pop();
	}

}

void print(queue<int>& q) {
	while(!q.empty()) {
		cout<<q.front()<<endl;
		q.pop();
	}
}


void solve(){
	queue<int> q;

	int k;
	cin>>k;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	reverse(q, k);
	print(q);
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
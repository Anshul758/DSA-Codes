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

bool sortBySec(const pair<int,int> &a, const pair<int,int> &b)
 {
   return (a.second<b.second);
 }

// void solve(){


// 	return;
// }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t;
	cin>>t;
	int n = 1;
	// t=1;
	while(t--){
	string s;
	cin>>s;
	string f;
	cin>>f;

	int count=0;

	if(f.length()==1){
		char a = f[0];
		for(int i=0; i<s.length(); i++) {
			char b = s[i];

			int rem = abs(b-a);
			if(rem>13)
				rem=26-rem;
			count+=rem;
		}
	}

	else {
		for(int i=0; i<s.length(); i++) {
			char c = s[i];
			int min = INT_MAX;

			for(auto x:f) {
				int a = abs(c-x);
				if(a>13)
					a=26-a;
				if(a<min)
					min = a;
			}
			count+=min;
		}
	}

	cout<<"Case #"<<n<<": "<<count<<endl;
	n++;
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}


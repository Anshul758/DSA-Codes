#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
// Policy based data structure 
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
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




// void solve(){
	
// }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t;
	cin>>t;
	// t=1;
	for(int j=1; j<=t; j++){
		int n,d,c,m;
	    cin>>n>>d>>c>>m;

	    string s;
	    cin>>s;

	    int cat=0,dog=0;
	
	    for(int i=0; i<n; i++) {
	    	if(s[i]=='C')
	    		cat++;
	    	else 
	    		dog++;
	    }

	    if(dog==0)
	    {
	    	cout<<"Case #"<<j<<": "<<"YES"<<endl;
	    }
	    else if(cat==0) {
	    	if(d>=dog) {
	    		cout<<"Case #"<<j<<": "<<"YES"<<endl;
	    	}
	    	else {
	    		cout<<"Case #"<<j<<": "<<"NO"<<endl;
	    	}
	    }
	    else {
	    	for(int i=0; i<n; i++) {
	    		if(s[i]=='C') {
	    			if(c==0) {
	    				if(dog==0) {
	    					cout<<"Case #"<<j<<": "<<"YES"<<endl;
	    					break;	
	    				}
	    				cout<<"Case #"<<j<<": "<<"NO"<<endl;
	    				break;
	    			}
	    			c--;
	    		}

	    		else if(s[i]=='D') {
	    			if(d==0) {
	    				cout<<"Case #"<<j<<": "<<"NO"<<endl;
	    				break;
	    			}
	    			d--;
	    			dog--;
	    			c+=m;
	    		}

	    		if(i==n-1) {
	    			cout<<"Case #"<<j<<": "<<"YES"<<endl;
	    		}
	    	}
	    }
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}
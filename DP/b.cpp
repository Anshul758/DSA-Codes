#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
// Policy based data structure 
template<class T> using oset=tree<int, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
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

bool cmp(pair<int,int> a, pair<int,int> b)
{
  int gaina = 2*a.first + a.second;
  int gainb = 2*b.first + b.second;

  if(gaina != gainb) return gaina < gainb;
  return a.first < b.first;
}

void solve(){
  int n;
  cin >> n;

  int x[n+1], y[n+1];

  for(int i = 1 ; i <= n ; i++) cin >> x[i];

  for(int i = 1 ; i <= n ; i++) cin >> y[i];

  int bob = 0;
  int alice = 0;

  vector<pair<int,int> >m;

  for(int i = 1 ; i <= n ; i++){
    m.push_back(make_pair(x[i], y[i]));
    alice += x[i];
  }

  sort(m.begin(), m.end(), cmp);
  int answer = 0;
  for(int i = n - 1 ; i >= 0 ; i--)
  {
    if(bob > alice) break;
    answer++;
    bob += (m[i].first + m[i].second);
    alice -= (m[i].first);
  }

  rep(i,0,n) {
  	cout<<m[i].first<<" "<<m[i].second<<endl;;
  }

  // cout << answer << endl;

	// int n,h;cin>>n>>h;
	// vector<int>v(n);
	// for(auto &i:v)cin>>i;
 //    sort(all(v),greater<int>());
 //    int p1 = v[0];
 //    int p2 = v[1];
 //    int cnt=0, cnt2=0;
 //    int h2 = h;
 //    int h3 = h; 
 //    h-=p1;
 //    h2-=p2;
 //    h3-=p1,h3-=p2;
 //    cnt2+=2;
 //    cnt++;
 //    int power = ceil((h/((p1+p2)*1.0)))*2;
 //    int power2 = ceil((h2/((p1+p2)*1.0)))*2;
 //    int power3 = ceil((h3/((p1+p2)*1.0)))*2;
 //    cout<<min({cnt+power,cnt+power2,cnt2+power3})<<'\n';
 }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t;
	cin>>t;
	// t=1;
	while(t--){
		solve();
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}

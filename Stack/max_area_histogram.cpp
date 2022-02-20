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
	 int n;
	 cin>>n;
	 int arr[n];

	 for(int i=0; i<n; i++) 
	 	cin>>arr[i];

	 //NSL (nearest smallest element on left) we find the arr of smallest element index on their left

	 stack<pair<int, int>> st;
	 vector<int> left;
	 int fixed_index1 = -1;

	 for(int i=0; i<n; i++) {
	 	if(st.empty())
	 		left.push_back(fixed_index1);
	 	else if(!st.empty() && st.top().first < arr[i])
	 		left.push_back(st.top().second);
	 	else if(!st.empty() && st.top().first >= arr[i]) {
	 		while(!st.empty() && st.top().first >= arr[i]) {
	 			st.pop();
	 		}
	 		if(st.empty())
	 			left.push_back(fixed_index1);
	 		else 
	 			left.push_back(st.top().second);
	 	}
	 	st.push({arr[i], i});
	}

	// for(int i=0; i<left.size(); i++) {
	// 	// left[i] = left[i] - i;
	// 	cout<<left[i]<<" ";
	// }
	// cout<<endl;

	//NSR (nearest smallest element on right)
	int mx = 0;

	for(int i=0; i<n; i++) 
		mx = max(arr[i], mx);

	stack<pair<int, int>> s;
	 vector<int> right;
	 int fixed_index = mx + 1;

	for(int i=n-1; i>=0; i--) 
	{
	 	if(s.empty())
	 		right.push_back(fixed_index);
	 	else if(!s.empty() && s.top().first < arr[i])
	 		right.push_back(s.top().second);
	 	else if(!s.empty() && s.top().first >= arr[i]) {
	 		while(!s.empty() && s.top().first >= arr[i]) {
	 			s.pop();
	 		}
	 		if(s.empty())
	 			right.push_back(fixed_index);
	 		else 
	 			right.push_back(s.top().second);
	 	}
	 	s.push({arr[i], i});
	}

	reverse(right.begin(), right.end());
	

	// for(int i=0; i<right.size(); i++) {
	// 	// right[i] = right[i] - i;
	// 	cout<<right[i]<<" ";
	// }
	// cout<<endl;


	int width[n];
	
	for(int i=0; i<n; i++) {
		width[i] = right[i] - left[i] - 1;
	}

	for(int i=0; i<n; i++) {
		arr[i] = arr[i]*width[i];
	}

	int maX = -99;
	for(int i=0; i<n; i++) 
		maX = max(maX, arr[i]);

	cout<<maX;

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
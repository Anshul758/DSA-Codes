// Method 1 of implementing Queue using two stacks

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


class Queue {
	stack<int> s1;
	stack<int> s2;

public:

	void push(int x) {
		s1.push(x);
	}

	int pop() {
		if(s1.empty() && s2.empty()) {
			cout<<"Queue is empty"<<endl;

			return -1;
		}

		if(s2.empty()) {
			while(!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		int topVal = s2.top();
		s2.pop();
		return topVal;
	}

	bool isEmpty() {
		if(s1.empty() && s2.empty()) 
			return true;

		return false;
	}
};

void solve(){
	Queue q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout<<q.pop()<<endl;
	q.push(5);

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
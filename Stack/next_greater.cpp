// Given an array, print the Next Greater Element (NGE) for every element.
// The Next greater Element for an element x is the first greater element on the right side of x in array.
// Elements for which no greater element exist, consider next greater element as -1.

#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;

	int arr[n];
	vector<int> v;
	// v.push_back(-1);
	
	stack<int> st;

	for(int i=0; i<n; i++)
		cin>>arr[i];
	// st.push(arr[n-1]);

	for(int i=n-1; i>=0; i--) {

		if(st.empty()) {
			v.push_back(-1);
		}

		else if(!st.empty() && st.top() > arr[i]) {
			v.push_back(st.top());
		}
		else {
			while(!st.empty() && st.top() <= arr[i]) {
				st.pop();
			}
			if(st.empty()) {
				v.push_back(-1);
			}
			else {
				v.push_back(st.top());
			}
		}

		st.push(arr[i]);
	}


	reverse(v.begin(), v.end());
	for(int i:v) 
		cout<<i<<" ";

	return 0;
}
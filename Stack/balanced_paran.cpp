#include<bits/stdc++.h>
using namespace std;

bool check(string s) {
	stack<char> st;
	bool ans = true;

	for(int i=0; i<s.length(); i++) 
	{
		if(s[i] == '(' || s[i] =='{' || s[i] =='[') {
			st.push(s[i]);
		}
		else if(s[i] == ')') {
			if(!st.empty() && st.top() == '(') 
				st.pop();
			else {
				ans = false;
				break;
			}
		}
		else if(s[i] == '}') {
			if(!st.empty() && st.top() == '{') 
				st.pop();
			else {
				ans = false;
				break;
			}
		}
		else if(!st.empty() && s[i] == ']') {
			if(st.top() == '[') 
				st.pop();
			else {
				ans = false;
				break;
			}
		}
		else {
			ans = false;
		}
	
	}	
	return ans;
	// if(!st.empty()) {
	// 	return ans;
	// }

}

int main()
{
	string s = "{([)}";
	if(check(s)) {
		cout<<"balanced";
	}
	else {
		cout<<"unbalanced";
	}
	return 0;
}
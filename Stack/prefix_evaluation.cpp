#include<bits/stdc++.h>
#include<stack>

using namespace std;

int evaluate(string s) {
	stack<int> st;

	for(int i=s.length()-1; i>=0; i--) {
		if(s[i]>='0'&&s[i]<='9') {
			st.push(s[i]-'0');
		}
		else {
			int op1 = st.top();
			st.pop();
			int op2 = st.top();
			st.pop();

			switch(s[i]) {
				case '+':
				st.push(op1+op2);
				break;
				case '-':
				st.push(op1-op2);
				break;
				case '*':
				st.push(op1*op2);
				break;
				case '/':
				st.push(op1/op2);
				break;
				case '^':
				st.push(pow(op1,op2));
				break;
			}
		}
	}
	return st.top();
}

int main()
{
	string s = "-+7*45+20";
	cout<<evaluate(s);
	// cout<<evaluate("-+7*45+40")<<endl;
	return 0;
}
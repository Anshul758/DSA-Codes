#include<bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixprefix(string s)
{	reverse(s.begin(), s.end());
    stack<char> st;
    st.push('N');
    
    int l = s.length();
    
    string ns;
    
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, 
        // add it to output string.
        if((s[i] >= 'a' && s[i] <= 'z')||
                (s[i] >= 'A' && s[i] <= 'Z'))
            ns+=s[i];
        // If the scanned character is an ‘(‘,
        // push it to the stack.
        else if(s[i] == ')')
        
        st.push(')');
        
        // If the scanned character is an ‘)’, 
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == '(')
        {
            while(st.top() != 'N' && st.top() != ')')
            {
                char c = st.top();
                st.pop();
                
                ns += c;
            }
            if(st.top() == ')')
            {
                char c = st.top();
                st.pop();
            }
        }
        
        // If an operator is scanned
        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            
            st.push(s[i]);
        }
    }
    
    // Pop all the remaining elements from the stack
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
    reverse(ns.begin(), ns.end());
    cout << ns << endl;
}

int main() 
{
	string s = "(a-b/c)*(a/k-l)";
	infixprefix(s);

	return 0;
}
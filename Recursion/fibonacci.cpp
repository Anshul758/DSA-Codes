#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
	// if(n==0)
	// 	return;

	// cout<<e+s<<" ";
	// return fibonacci(n-1,s,e+s);
	if(n==1)
		return 0;
	if(n==2)
		return 1;

	return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
	int n;
	cin>>n;
	// cout<<"0"<<" "<<"1"<<" ";
	// int e=0,s=1;
	cout<<fibonacci(n);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int printSum(int n) {
	if(n==0)
		return 0;

	int left_part = printSum(n-1);
	return left_part+n;
}

int main()
{
	int n;
	cin>>n;

	cout<<printSum(n)<<endl;
	return 0;
}
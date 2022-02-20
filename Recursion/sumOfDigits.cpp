#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) 
{
	if(n==0)
		return 0;

	int last = n%10;

	return sumOfDigits(n/10)+last;

	// if(n==1)
	// 	return 1;

	// return sumOfDigits(n-1)*n;
}

int main()
{
	int n;
	cin>>n;

	cout<<sumOfDigits(n)<<endl;
	return 0;
}
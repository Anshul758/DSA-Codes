#include<bits/stdc++.h>
using namespace std;

int main()
{	
	double x;
	vector<double> v;
	

	while(cin>>x) {
		v.push_back(x);
	}

	vector<double> ans;

	for(int i=0; i<v.size(); i++) {
		int b = v[i];
		string a = to_string(b);
		bool check = false;

		for(int j=0; j<a.size(); j++) {
			if(a[j]=='6') {
				check = true;	
			}
			// t.push_back(a[i]);
		}
		replace(a.begin(), a.end(), '6', '9');
		if(check) 
			reverse(a.begin(), a.end());
		
		// if(check)
		ans.push_back(stoi(a));
	}
	float sum = 0;
	for(int i=0;i<ans.size();i++) 
		sum += ans[i];
	printf("%.2f", sum/ans.size());

	return 0;
}
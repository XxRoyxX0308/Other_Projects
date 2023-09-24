#include<bits/stdc++.h>
using namespace std;

int n,m,a;
vector<int> aa;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		aa.insert(lower_bound(aa.begin(),aa.end(),a),a);
	}
	
	for(int i=0;i<n;i++) cout<<aa[i]<<" ";
}

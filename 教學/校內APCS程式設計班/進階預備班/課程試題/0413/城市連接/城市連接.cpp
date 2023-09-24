#include<bits/stdc++.h>
using namespace std;

set<int> st[200010];
long long n,m,a,b;

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		st[a].insert(b);
		st[b].insert(a);
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>a;
		for(auto j=st[a].begin();j!=st[a].end();j++)
		{
			cout<<*j<<" ";
		}
		cout<<"\n";
	}
}

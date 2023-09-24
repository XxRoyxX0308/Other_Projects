#include<bits/stdc++.h>
using namespace std;

int n,m,a,b;
vector<int> aa[100010];

int main()
{
	while(cin>>n>>m)
	{
		aa[n].push_back(m);
		aa[m].push_back(n);
	}
	
	for(int i=0;i<100010;i++)
	{
		if(aa[i].size()>a)
		{
			a=aa[i].size();
			b=i;
		}
	}
	
	sort(aa[b].begin(),aa[b].end(),greater<int>());
	int j=aa[b].size();
	for(int i=0;i<j;i++)
	{
		cout<<aa[b][i]<<" ";
	}
}

#include<bits/stdc++.h>
using namespace std;

int x,y,aa[110][110];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin>>x>>y;
	
	for(int i=0;i<110;i++)
	{
		aa[0][i]=1;
		aa[i][0]=1;
	}
	
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			aa[i][j]=aa[i-1][j]+aa[i][j-1];
			cout<<aa[i][j]<<" ";
		}
		cout<<"\n";
	}
}

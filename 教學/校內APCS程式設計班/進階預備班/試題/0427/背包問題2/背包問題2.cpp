#include<bits/stdc++.h>
using namespace std;

long long n,m,a,b,aa[2][2000010],bb[1000010][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>b;
		bb[i][0]=a;
		bb[i][1]=b;
	}
	
	for(long long i=1;i<=n;i++)
	{
		for(long long j=bb[i][0];j<=m;j++)
		{
			aa[1][j]=max(bb[i][1]+aa[0][j-bb[i][0]],aa[0][j]);
		}
		for(int j=bb[i][0];j<=m;j++)
		{
			aa[0][j]=aa[1][j];
		}
	}
	
	cout<<aa[0][m];
}

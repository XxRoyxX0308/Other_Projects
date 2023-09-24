#include<bits/stdc++.h>
using namespace std;

long long n,m,a,b,aa[100][100010],bb[100][2];

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		bb[i][0]=a;
		bb[i][1]=b;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(bb[i][0]<=j) aa[i][j]=max(bb[i][1]+aa[i-1][j-bb[i][0]],aa[i-1][j]);
			else aa[i][j]=aa[i-1][j];
		} 
	}
	
	cout<<aa[n][m];
}

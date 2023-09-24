#include<bits/stdc++.h>
using namespace std;

int aa[21][21],n,m,a,ans;

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>aa[i][j];
	
	for(int k=0;k<m;k++)
	{
		cin>>a;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a==aa[i][j]) aa[i][j]=0;
	}
	
	int x1=0,y1=0;
	for(int i=0;i<n;i++)
	{
		int x=0,y=0;
		for(int j=0;j<n;j++)
		{
			if(aa[i][j]==0) x++;
			if(aa[j][i]==0) y++;
		}
		if(x==n) ans++;
		if(y==n) ans++;
		
		if(aa[i][i]==0) x1++;
		if(aa[i][n-i-1]==0) y1++;
	}
	if(x1==n) ans++;
	if(y1==n) ans++;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<aa[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<ans<<"\n";
}

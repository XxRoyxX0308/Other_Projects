#include<bits/stdc++.h>
using namespace std;

int x,y,n,aa[110][110];

int main()
{
	cin>>x>>y>>n;
	for(int i=0;i<x;i++) for(int j=0;j<y;j++) cin>>aa[i][j];
	
	if(n==1)
	{
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				cout<<aa[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else if(n==2)
	{
		for(int j=0;j<y;j++)
		{
			for(int i=x-1;i>=0;i--)
			{
				cout<<aa[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else if(n==3)
	{
		for(int i=x-1;i>=0;i--)
		{
			for(int j=y-1;j>=0;j--)
			{
				cout<<aa[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else
	{
		for(int j=y-1;j>=0;j--)
		{
			for(int i=0;i<x;i++)
			{
				cout<<aa[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}

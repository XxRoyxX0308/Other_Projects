#include<bits/stdc++.h>
using namespace std;

long long n,m,aa[100][100];

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++) aa[i][0]=1;
	for(int j=0;j<m;j++) aa[0][j]=1;
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			aa[i][j]=aa[i-1][j]+aa[i][j-1];
		}
	}
	
	cout<<aa[n-1][m-1];
}

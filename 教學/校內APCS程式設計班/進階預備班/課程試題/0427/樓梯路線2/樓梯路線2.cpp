#include<bits/stdc++.h>
using namespace std;

long long n,m,aa[1000][1000];

int main()
{
	cin>>n>>m;

	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>aa[i][j];
	for(int i=1;i<n;i++) aa[i][0]+=aa[i-1][0];
	for(int j=1;j<m;j++) aa[0][j]+=aa[0][j-1];
	for(int i=1;i<n;i++) for(int j=1;j<m;j++) aa[i][j]+=min(aa[i-1][j],aa[i][j-1]);

	cout<<aa[n-1][m-1];
}

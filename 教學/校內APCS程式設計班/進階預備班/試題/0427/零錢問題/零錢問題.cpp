#include<bits/stdc++.h>
using namespace std;

long long coins[6]={1,3,7,13,97,211},aa[1000010];

int main()
{
	aa[0]=1;
	for(int i=0;i<6;i++) for(int j=coins[i];j<=1000000;j++) aa[j]+=aa[j-coins[i]];
	
	int n,a;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cout<<aa[a]<<"\n";
	}
}

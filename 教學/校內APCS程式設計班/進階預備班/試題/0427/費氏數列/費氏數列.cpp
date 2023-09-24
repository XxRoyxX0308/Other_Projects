#include<bits/stdc++.h>
using namespace std;

long long dp[100];

int main()
{
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=80;i++) dp[i]=dp[i-1]+dp[i-2];
	
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cout<<dp[a]<<"\n";
	}
}

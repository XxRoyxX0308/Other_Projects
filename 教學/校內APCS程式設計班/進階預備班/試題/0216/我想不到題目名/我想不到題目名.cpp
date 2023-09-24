#include<bits/stdc++.h>
using namespace std;

long long n,k,aa[2010],bb[2010][2010],ans=-1000000000000000;

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>aa[i];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) bb[i][j]=aa[i]*aa[j];
	
	for(int i=1;i<n-k+1;i++)
	{
		long long an=0,j;
		for(j=0;j<k;j++)
		{
			an+=bb[i+j][j];
		}
		ans=max(ans,an);
		//cout<<an<<endl;
		
		for(int ii=i+k;ii<n;ii++,j++)
		{
			an+=bb[ii][j]-bb[ii-k][j-k];
			ans=max(ans,an);
			//cout<<ii<<" "<<j<<" "<<an<<endl;
		}
	}
	for(int i=1;i<n-k+1;i++)
	{
		long long an=0,j;
		for(j=0;j<k;j++)
		{
			an+=bb[j][i+j];
		}
		ans=max(ans,an);
		//cout<<an<<endl;
		
		for(int ii=i+k;ii<n;ii++,j++)
		{
			an+=bb[j][ii]-bb[j-k][ii-k];
			ans=max(ans,an);
			//cout<<j<<" "<<ii<<" "<<an<<endl;
		}
	}
	cout<<ans;
}

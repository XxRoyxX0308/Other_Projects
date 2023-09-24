#include<bits/stdc++.h>
using namespace std;

int aa[100000],bb[100010][100010],a,b,ans=-1e8;

int aaa(int x,int y)
{
	if(x>=12) return x+2;
	else return aaa(x+abs(y),y+60)+x;
}

int main()
{
	cin>>a>>b;
	for(int i=0;i<a;i++) cin>>aa[i];
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			bb[i][j]=aaa(aa[i],aa[j]);
			//cout<<bb[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	for(int i=0;i<=a-b;i++)
	{
		for(int j=0;j<=a-b;j++)
		{
			int x=0;
			for(int k=0;k<b;k++) x+=bb[i+k][j+k];
			ans=max(ans,x);
		}
	}
	
	cout<<ans<<"\n";
}

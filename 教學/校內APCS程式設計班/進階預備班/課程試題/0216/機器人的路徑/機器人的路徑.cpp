#include<bits/stdc++.h>
using namespace std;

int n,m,aa[110][110],mina=1000000,x,y,xx[4]={1,-1,0,0},yy[4]={0,0,1,-1},a,xa,ya,ans;

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>aa[i][j];
			if(mina>aa[i][j])
			{
				mina=aa[i][j];
				x=i;
				y=j; 
			} 
		}
	}
	ans+=aa[x][y];
	aa[x][y]=-1;
	
	while(true)
	{
		a=1000000;
		xa=0;
		for(int i=0;i<4;i++)
		{
			if(x+xx[i]>0 and x+xx[i]<n+1 and y+yy[i]>0 and y+yy[i]<m+1 and aa[x+xx[i]][y+yy[i]]>=0)
			{
				if(aa[x+xx[i]][y+yy[i]]<a)
				{
					a=aa[x+xx[i]][y+yy[i]];
					xa=x+xx[i];
					ya=y+yy[i];
				}
			}
		}
		
		if(xa) ans+=aa[xa][ya];
		else break;
		aa[xa][ya]=-1;
		x=xa;
		y=ya;
	}
	cout<<ans;
}

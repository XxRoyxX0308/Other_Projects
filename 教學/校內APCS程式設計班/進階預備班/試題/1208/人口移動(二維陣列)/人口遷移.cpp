#include<bits/stdc++.h>
using namespace std;

int x,y,n,t,aa[110][110],xx[4]={-1,0,1,0},yy[4]={0,1,0,-1};

int main()
{
	cin>>x>>y>>n>>t;
	for(int i=0;i<110;i++) for(int j=0;j<110;j++) aa[i][j]=-1;
	for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) cin>>aa[i][j];
	
	for(int m=0;m<t;m++)
	{
		int bb[110][110];
		for(int i=0;i<110;i++) for(int j=0;j<110;j++) bb[i][j]=-1;
		
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				if(aa[i][j]!=-1)
				{
					bb[i][j]++;
					for(int l=0;l<4;l++)
					{
						if(aa[i+xx[l]][j+yy[l]]!=-1 and aa[i][j]-aa[i][j]/n>=0)
						{
							aa[i][j]-=aa[i][j]/n;
							bb[i+xx[l]][j+yy[l]]+=aa[i][j]/n;
						}
					}
					bb[i][j]+=aa[i][j];
				}
			}
		}
		for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) aa[i][j]=bb[i][j];
	}
	
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cout<<aa[i][j]<<" ";
		}
		cout<<"\n";
	}
}

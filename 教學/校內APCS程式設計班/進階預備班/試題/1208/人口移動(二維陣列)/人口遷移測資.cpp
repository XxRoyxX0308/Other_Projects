#include<bits/stdc++.h>
using namespace std;

fstream file;
int x,y,n,t,aa[110][110],xx[4]={-1,0,1,0},yy[4]={0,1,0,-1},max1,min1;

int main()
{
	for(int k=1;k<=20;k++)
	{
		min1=1; max1=100;
		x=rand()%(max1-min1+1)+min1;
		y=rand()%(max1-min1+1)+min1;
		min1=1; max1=1e3;
		n=rand()%(max1-min1+1)+min1;
		t=rand()%(max1-min1+1)+min1;
		file.open(to_string(k)+".in",ios::out);
		file<<x<<" "<<y<<" "<<n<<" "<<t<<"\n"; 
		
		for(int i=0;i<110;i++) for(int j=0;j<110;j++) aa[i][j]=-1;
		min1=1; max1=1e5;
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				int w=rand()%(5)-1;
				if(w!=-1) aa[i][j]=rand()%(max1-min1+1)+min1;
				else aa[i][j]=-1;
				file<<aa[i][j]<<" ";
			}
			file<<"\n";
		}
		file.close();
		
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
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				file<<aa[i][j]<<" ";
			}
			file<<"\n";
		}
		file.close();
	}
}

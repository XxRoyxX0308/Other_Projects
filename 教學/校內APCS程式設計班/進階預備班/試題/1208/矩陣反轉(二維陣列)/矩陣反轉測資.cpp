#include<bits/stdc++.h>
using namespace std;

fstream file;
int x,y,n,aa[110][110],max1,min1;

int main()
{
	for(int k=1;k<=20;k++)
	{
		min1=1; max1=100;
		x=rand()%(max1-min1+1)+min1;
		y=rand()%(max1-min1+1)+min1;
		min1=1; max1=4;
		n=rand()%(max1-min1+1)+min1;
		file.open(to_string(k)+".in",ios::out);
		file<<x<<" "<<y<<" "<<n<<"\n";
		
		min1=-1e3; max1=1e3;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				aa[i][j]=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
				file<<aa[i][j]<<" ";
			}
			file<<"\n";
		}
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		if(n==1)
		{
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<y;j++)
				{
					file<<aa[i][j]<<" ";
				}
				file<<"\n";
			}
		}
		else if(n==2)
		{
			for(int j=0;j<y;j++)
			{
				for(int i=x-1;i>=0;i--)
				{
					file<<aa[i][j]<<" ";
				}
				file<<"\n";
			}
		}
		else if(n==3)
		{
			for(int i=x-1;i>=0;i--)
			{
				for(int j=y-1;j>=0;j--)
				{
					file<<aa[i][j]<<" ";
				}
				file<<"\n";
			}
		}
		else
		{
			for(int j=y-1;j>=0;j--)
			{
				for(int i=0;i<x;i++)
				{
					file<<aa[i][j]<<" ";
				}
				file<<"\n";
			}
		}
		file.close();
	}
}

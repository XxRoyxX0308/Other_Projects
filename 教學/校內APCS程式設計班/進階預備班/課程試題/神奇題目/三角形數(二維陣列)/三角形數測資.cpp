#include<bits/stdc++.h>
using namespace std;

fstream file;
long long x,y,aa[40][40],max1=30,min1=1;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		x=rand()%(max1-min1+1)+min1;
		y=rand()%(max1-min1+1)+min1;
		
		file.open(to_string(k)+".in",ios::out);
		file<<x<<" "<<y;
		file.close();
		
		for(int i=0;i<40;i++)
		{
			aa[0][i]=1;
			aa[i][0]=1;
		}
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				aa[i][j]=aa[i-1][j]+aa[i][j-1];
				file<<aa[i][j]<<" ";
			}
			file<<"\n";
		}
		file.close();
	}
}

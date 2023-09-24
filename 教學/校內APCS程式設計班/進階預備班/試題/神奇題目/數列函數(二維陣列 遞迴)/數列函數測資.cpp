#include<bits/stdc++.h>
using namespace std;

fstream file;
int aa[100000],bb[100010][100010],a,b,ans=-1e8,max1,min1;

int aaa(int x,int y)
{
	if(x>=12) return x+2;
	else return aaa(x+abs(y),y+60)+x;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		
		if(k<=10){min1=1; max1=1000;}
		else {min1=1; max1=100000;}
		a=rand()%(max1-min1+1)+min1;
		min1=1; max1=a;
		b=rand()%(max1-min1+1)+min1;
		file<<a<<" "<<b<<"\n";
		
		min1=-1e5; max1=1e5;
		for(int i=0;i<a;i++)
		{
			aa[i]=rand()%(max1-min1+1)+min1;
			file<<aa[i]<<" ";
		}
		file.close();
		
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
		
		file.open(to_string(k)+".out",ios::out);
		file<<ans<<"\n";
		file.close();
		ans=-1e8;
	}
}

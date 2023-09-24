#include<bits/stdc++.h>
using namespace std;

int n,m,a,bb[10010],min1,max1;
fstream file;

struct tt
{
	int x,y;
}aa[10010];

bool q(tt a,tt b)
{
	if(a.x!=b.x) return a.x<b.x;
	else return a.y<b.y;
}

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		min1=1; max1=10000;
		n=rand()%(max1-min1+1)+min1;
		m=rand()%(max1-min1+1)+min1;
		file.open(to_string(k)+".in",ios::out);
		file<<n<<" "<<m<<"\n";
		
		min1=-1000; max1=1000;
		for(int i=0;i<n;i++)
		{
			aa[i].x=rand()%(max1-min1+1)+min1;
			aa[i].y=i+1;
			file<<aa[i].x<<" ";
		}
		file<<"\n";
		
		sort(aa,aa+n,q);
		for(int i=0;i<n;i++) bb[i]=aa[i].x;
		
		for(int i=0;i<m;i++)
		{
			a=rand()%(max1-min1+1)+min1;
			bb[lower_bound(bb,bb+n,a)-bb]=a;
			file<<a<<" ";
		}
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(aa[j].y==i+1)
				{
					file<<bb[j]<<" ";
					break;
				}
			}
		}
		file.close();
	} 
}

/*
4 2
37 95836 283 283
77
286
*/

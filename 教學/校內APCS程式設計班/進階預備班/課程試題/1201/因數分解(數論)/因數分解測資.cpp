#include<bits/stdc++.h>
using namespace std;

fstream file;
long long a,b,min1=0,max1=1e2;

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		if(k==11) max1=1e6;
		b=0;
		a=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		
		file.open(to_string(k)+".in",ios::out);
		file<<a;
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		
		for(long long i=2;i<=a;i++)
		{
			if(a%i==0)
			{
				if(b!=0) file<<" * ";
				
				long long x=1;
				a/=i;
				while(a%i==0)
				{
					a/=i;
					x++;
				}
				
				b=1;
				if(x!=1) file<<i<<"^"<<x;
				else file<<i;
			}
		}
		file.close();
	}
}

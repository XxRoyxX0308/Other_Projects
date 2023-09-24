#include<bits/stdc++.h>
using namespace std;

long long a,b;

int main()
{
	cin>>a;
	
	for(long long i=2;i<=a;i++)
	{
		if(a%i==0)
		{
			if(b!=0) cout<<" * ";
			
			long long x=1;
			a/=i;
			while(a%i==0)
			{
				a/=i;
				x++;
			}
			
			b=1;
			if(x!=1) cout<<i<<"^"<<x;
			else cout<<i;
		}
	} 
}

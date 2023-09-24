#include<bits/stdc++.h>
using namespace std;

fstream file;
long long ans,min1,max1,yee,yee1,l;
string s;
stack<int> st,st1;

int main()
{
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		min1=1; max1=100;
		yee1=rand()%(max1-min1+1)+min1;
		file<<yee1;
		
		l=2;
		ans=0;
		while(!(ans/10000000000000) and !(-ans/10000000000000))
		{
			yee=rand()%(max1-min1+1)+min1;
			if(yee1==yee) continue;
			if(yee%4==0)
			{
				yee1+=yee;
				file<<"+";
			}
			else if(yee%4==1)
			{
				yee1-=yee;
				file<<"-";
			}
			else if(yee%4==2)
			{
				file<<"*";
				if(l==0)
				{
					ans*=yee1;
				}
				else if(l==1)
				{
					ans/=yee1;
					if(ans==0) break;
				}
				else if(l==2)
				{
					ans=yee1; 
				}
				l=0;
				yee1=yee;
			}
			else
			{
				file<<"/";
				if(l==0)
				{
					ans*=yee1;
				}
				else if(l==1)
				{
					ans/=yee1;
					if(ans==0) break;
				}
				else if(l==2)
				{
					ans=yee1; 
				}
				l=1;
				yee1=yee;
			}
			
			file<<yee;
		}
		file.close();
		if(ans==0)
		{
			k--;
			continue;
		}
		
		if(l==0)
		{
			ans*=yee1;
		}
		else if(l==1)
		{
			ans/=yee1;
		}
		file.open(to_string(k)+".out",ios::out);
		file<<ans;
		file.close();
	}
}

#include<bits/stdc++.h>
using namespace std;

string a,b,c;
int aa[1000010],bb[1000010];
bool t;

int main()
{
	cin>>a>>c>>b;
	for(int i=0;i<a.size();i++) aa[i]=a[a.size()-i-1]-'0';
	for(int i=0;i<b.size();i++) bb[i]=b[b.size()-i-1]-'0';
	
	if(c=="+")
	{
		for(int i=0;i<a.size();i++)
		{
			aa[i]+=bb[i];
			if(aa[i]>=10) 
			{
				aa[i]-=10;
				aa[i+1]+=1;
			}
		}
	}
	else if(c=="-")
	{
		for(int i=0;i<a.size();i++)
		{
			aa[i]-=bb[i];
			if(aa[i]<0) 
			{
				aa[i]+=10;
				aa[i+1]-=1;
			}
		}
	}
	
	for(int i=1000001;i>=0;i--)
	{
		if(aa[i]==0 and !t) continue;
		else t=1;
		cout<<aa[i];
	}
}

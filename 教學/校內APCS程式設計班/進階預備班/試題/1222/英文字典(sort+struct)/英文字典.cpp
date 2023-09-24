#include<bits/stdc++.h>
using namespace std;

int a,z=0;
struct tt
{
	int x[30];
	string s;
}mystruct[100000];

bool q(tt x,tt y)
{
	z++;
	if(x.x[z]!=y.x[z])
	{
		int x1=x.x[z],y1=y.x[z];
		z=0;
		return x1<y1;
	}
	else return q(x,y);
}

int main()
{
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>mystruct[i].s;
		for(int j=1;j<=mystruct[i].s.size();j++)
		{
			mystruct[i].x[j]=mystruct[i].s[j-1]-'a'+1;
		}
	}
	
	sort(mystruct,mystruct+a,q);
	for(int i=0;i<a;i++)
	{
		cout<<mystruct[i].s<<"\n";
	}
}

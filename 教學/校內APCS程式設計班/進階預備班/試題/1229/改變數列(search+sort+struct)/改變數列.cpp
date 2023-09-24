#include<bits/stdc++.h>
using namespace std;

int n,m,a,bb[10010];

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
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>aa[i].x;
		aa[i].y=i+1;
	}
	
	sort(aa,aa+n,q);
	for(int i=0;i<n;i++) bb[i]=aa[i].x;
	
	for(int i=0;i<m;i++)
	{
		cin>>a;
		bb[lower_bound(bb,bb+n,a)-bb]=a;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(aa[j].y==i+1)
			{
				cout<<bb[j]<<" ";
				break;
			}
		}
	}
}

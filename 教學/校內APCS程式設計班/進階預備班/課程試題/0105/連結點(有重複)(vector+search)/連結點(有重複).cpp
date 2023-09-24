#include<bits/stdc++.h>
using namespace std;

int n,m,a,b;
vector<int> aa[2010];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	while(cin>>n>>m)
	{
		if(aa[n].empty()) aa[n].push_back(m);
		if(aa[m].empty()) aa[m].push_back(n);
		
		int r=aa[n].size(),l=0,o,x,y=1;
		while(l<=r)
		{
			o=(r+l)/2;
			x=o;
			
			if(aa[n][o]==m)
			{
				y=0;
				break;
			}

			if(aa[n][o]<m) l=o+1;
			else r=o-1;
		}
		if(y)
		{
			for(int i=x;i>=0;i--) if(aa[n][i]>m and (i==0 or aa[n][i-1]<m)) {aa[n].insert(aa[n].begin()+i,m); break;}
		}
		
		r=aa[m].size(); l=0 ;y=1;
		while(l<=r)
		{
			o=(r+l)/2;
			x=o;
			
			if(aa[m][o]==n)
			{
				y=0;
				break;
			}

			if(aa[m][o]<n) l=o+1;
			else r=o-1;
		}
		if(y)
		{
			for(int i=x;i>=0;i--) if(aa[m][i]>n and (i==0 or aa[m][i-1]<n)) {aa[m].insert(aa[m].begin()+i,n); break;}
		}
		cout<<aa[n].size()<<" "<<aa[m].size()<<endl;
	}
	
	for(int i=0;i<2010;i++)
	{
		if(aa[i].size()>a)
		{
			a=aa[i].size();
			b=i;
		}
	}
	
	int j=aa[b].size();
	for(int i=0;i<j;i++)
	{
		cout<<aa[b][i]<<" ";
	} 
}


/*
3 5
3 8
3 5
8 3
3 8
3 2
EOF
*/

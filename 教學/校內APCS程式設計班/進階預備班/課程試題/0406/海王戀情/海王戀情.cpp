#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,day=0;
	map<string,int> m;
	string s;
	
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>s>>a;
			
			if(m[s]>day) m[s]+=a;
			else m[s]=day+a;
		}
		day++;
	}
	
	for(auto &mm:m) if(mm.second>day) cout<<mm.first<<"\n";
}

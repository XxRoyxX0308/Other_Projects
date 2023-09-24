#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,a,ans=0;
	string s,s1;
	map<string,int> m;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s>>a;
		m[s]=a;
	}
	cin>>s;
	
	for(int i=1;i<=s.size();i++)
	{
		s1="";
		for(int j=0;j<i;j++)
		{
			s1+=s[j];
		}
		ans+=m[s1];
		for(int j=i;j<s.size();j++)
		{
			s1.erase(s1.begin());
			s1+=s[j];
			ans+=m[s1];
		}
	}
	cout<<ans;
}

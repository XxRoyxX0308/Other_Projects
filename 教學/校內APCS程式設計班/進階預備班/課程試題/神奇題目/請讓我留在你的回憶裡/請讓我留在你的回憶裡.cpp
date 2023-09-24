#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=0;
	string s;
	getline(cin,s);
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=' ')
		{
			if(n%2==1) cout<<" ";
			cout<<s[i];
			n=0;
		}
		else n++;
	}
}

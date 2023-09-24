#include<bits/stdc++.h>
using namespace std;

int main()
{
	bool b=0;
	string a;
	cin>>a;
	
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]-'0') b=1;
		if(b) cout<<a[i];
	}
	if(!b) cout<<"0";
}

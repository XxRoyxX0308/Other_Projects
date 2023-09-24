#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long x=0,y=0;
	string a;
	cin>>a;
	
	for(int i=0,j=1;i<a.size(),j<a.size();i+=2,j+=2)
	{
		x+=a[i]-'0';
		y+=a[j]-'0'; 
	}
	if(a.size()%2) x+=a[a.size()-1]-'0';
	cout<<abs(y-x);
}

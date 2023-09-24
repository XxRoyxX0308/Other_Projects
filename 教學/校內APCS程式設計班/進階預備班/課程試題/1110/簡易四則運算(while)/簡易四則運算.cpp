#include<bits/stdc++.h>
using namespace std;

long long a,a1;
string b;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	while(cin>>a>>b>>a1)
	{
		if(b=="+") cout<<a+a1<<endl;
		else if(b=="-") cout<<a-a1<<endl;
		else if(b=="*") cout<<a*a1<<endl;
		else cout<<a/a1<<endl;
	}
}

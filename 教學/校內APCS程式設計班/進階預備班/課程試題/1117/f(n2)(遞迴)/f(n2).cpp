#include<bits/stdc++.h>
using namespace std;

long long f(long long x)
{
	if(x==0) return 1;
	else return f(x/2)+x;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long n;
		cin>>n;
		cout<<f(n)<<"\n";
	}
}

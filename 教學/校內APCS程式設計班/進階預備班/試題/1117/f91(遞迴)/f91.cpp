#include<bits/stdc++.h>
using namespace std;

int aaa(int N)
{
	if(N>=101) return N-10;
	else return aaa(aaa(N+11));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int a;
	
	while(cin>>a)
	{
		if(a==0) break;
		cout<<"f91("<<a<<") = "<<aaa(a)<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

int a,ans,aa[1000010];

void aaa(int y)
{
	if(aa[y]!=0)
	{
		int z=aa[y];
		aa[y]=0;
		aaa(z);
	}
	else ans++;
}

int main()
{
	cin>>a;
	for(int i=1;i<=a;i++) cin>>aa[i];
	
	for(int i=1;i<=a;i++) if(aa[i]!=0) aaa(i);
	cout<<ans<<"\n";
}

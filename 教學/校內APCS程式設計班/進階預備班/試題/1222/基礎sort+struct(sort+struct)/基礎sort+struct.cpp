#include<bits/stdc++.h>
using namespace std;

struct tt
{
	long long n,m;
}mystruct[100010];
int a,aa[100010],bb[100010];

bool q(tt a,tt b)
{
	if(a.n!=b.n) return(a.n<b.n);
	else return(a.m>b.m);
}

int main()
{
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>mystruct[i].n>>mystruct[i].m;
		aa[i]=mystruct[i].n;
		bb[i]=mystruct[i].m;
	}
	
	//sort(aa,aa+a);
	//for(int i=a-1;i>=0;i--) cout<<aa[i]<<" ";
	//cout<<"\n";
	//sort(bb,bb+a,greater<int>());
	//for(int i=a-1;i>=0;i--) cout<<bb[i]<<" ";
	//cout<<"\n";
	
	sort(mystruct,mystruct+a,q);
	for(int i=0;i<a;i++) cout<<mystruct[i].n<<" "<<mystruct[i].m<<"\n";
}

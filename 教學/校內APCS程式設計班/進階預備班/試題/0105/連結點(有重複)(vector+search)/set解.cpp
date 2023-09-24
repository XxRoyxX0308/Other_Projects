#include<bits/stdc++.h>
using namespace std;

int n,m,a,b;
set<int> s[2010];

int main()
{
	while(cin>>n>>m) {s[n].insert(m); s[m].insert(n);}
	for(int i=0;i<2010;i++) if(s[i].size()>a) {a=s[i].size(); b=i;}
	for(const auto &t:s[b]) cout<<t<<" "; 
}

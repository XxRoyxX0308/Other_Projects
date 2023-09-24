#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int k=1;k<=20;k++)
	{
		int n,m,a;
		bool ch=0;
		set<int> s;
		string f=to_string(k);
		ifstream in(f+".in");
		in>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				in>>a;
				if(s.find(a)!=s.end()){
					cout<<k<<' '<<i<<' '<<j<<' '<<a<<'\n';
					ch=1;
					break;
				}
				s.insert(a);
			}
			if(ch) break;
		}
	}
	return 0;
}

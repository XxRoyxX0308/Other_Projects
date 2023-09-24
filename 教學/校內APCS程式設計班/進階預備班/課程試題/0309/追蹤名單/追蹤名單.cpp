#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	string a;
	set<string> st;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(st.count(a)) st.erase(a);
		else st.insert(a);
	}
	
	for(auto &s:st)
	{
		cout<<s<<" ";
	}
}
 

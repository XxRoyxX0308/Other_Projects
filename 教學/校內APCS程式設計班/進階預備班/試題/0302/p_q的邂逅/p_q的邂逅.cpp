#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int ans=0;
		string s;
		stack<bool> st;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='p') st.push(0);
			else if(s[j]=='q')
			{
				if(st.size()!=0 and st.top()==0)
				{
					st.pop();
					ans++;
				}
				else st.push(1);
			}
		}
		cout<<ans<<"\n";
	}
}

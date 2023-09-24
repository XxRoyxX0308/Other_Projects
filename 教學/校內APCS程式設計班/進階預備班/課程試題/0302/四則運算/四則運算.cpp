#include<bits/stdc++.h>
using namespace std;

long long ans;
string s;
stack<int> st,st1;

int main()
{
	cin>>s;
	
	long long a=0,b=0,m=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='+')
		{
			b+=a;
			a=0;
			m=1;
		}
		else if(s[i]=='-')
		{
			b-=a;
			a=0;
			m=1;
		}
		else if(s[i]=='*')
		{
			b+=a;
			a=0;
			m=1;
			st.push(b);
			st1.push(0);
			b=0;
		}
		else if(s[i]=='/')
		{
			b+=a;
			a=0;
			m=1;
			st.push(b);
			st1.push(1);
			b=0;
		}
		else
		{
			a+=(s[i]-'0')*m;
			m*=10;
		}
	}
	b+=a;
	st.push(b);
	
	
	ans+=st.top();
	st.pop();
	while(!st1.empty())
	{
		if(st1.top()==0)
		{
			st1.pop();
			ans*=st.top();
			st.pop();
		}
		else
		{
			st1.pop();
			ans/=st.top();
			st.pop();
		}
	}
	
	cout<<ans;
}

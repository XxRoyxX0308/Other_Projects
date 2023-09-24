#include<bits/stdc++.h>
using namespace std;

int aa[26],b,b1;
string a;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	while(getline(cin,a))
	{
		if(a=="EOF") break;
		b=0;
		b1=0;
		for(int i=0;i<26;i++) aa[i]=0;
		
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>='A' and a[i]<='Z') aa[a[i]-'A']++;
			else if(a[i]>='a' and a[i]<='z') aa[a[i]-'a']++;
		}
		for(int i=0;i<26;i++)
		{
			if(b<aa[i])
			{
				b=aa[i];
				b1=i;
			}
		}
		
		cout<<char(b1+'A')<<" "<<b<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

fstream file;
int min1,max1;

int main()
{
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		
		long long n,n1,a,ans=0;
		string s,s1;
		map<string,int> m,m1;
		
		min1=1; max1=10000;
		n=rand()%(max1-min1+1)+min1;
		file<<n<<endl;
		//cin>>n;
		
		for(int i=0;i<n;i++)
		{
			min1=1; max1=12;
			s="";
			n1=rand()%(max1-min1+1)+min1;
			min1=0; max1=25;
			for(int j=0;j<n1;j++)
			{
				s+=rand()%(max1-min1+1)+min1+'a';
			}
			min1=1; max1=100;
			a=rand()%(max1-min1+1)+min1;
			//cin>>s>>a;
			
			if(m1[s])
			{
				i--;
				continue;
			}
			m1[s]=1;
			file<<s<<" "<<a<<endl;
			
			m[s]=a;
		}
		
		min1=1; max1=30;
		s="";
		n1=rand()%(max1-min1+1)+min1;
		min1=0; max1=25;
		for(int j=0;j<n1;j++)
		{
			s+=rand()%(max1-min1+1)+min1+'a';
		}
		//cin>>s;
		file<<s;
		file.close();
		
		for(int i=1;i<=s.size();i++)
		{
			s1="";
			for(int j=0;j<i;j++)
			{
				s1+=s[j];
			}
			ans+=m[s1];
			for(int j=i;j<s.size();j++)
			{
				s1.erase(s1.begin());
				s1+=s[j];
				ans+=m[s1];
			}
		}
		
		file.open(to_string(k)+".out",ios::out);
		file<<ans;
		file.close();
	} 
}

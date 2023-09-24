#include<bits/stdc++.h>
using namespace std;

fstream file;
int a,n,min1,max1,s_size;

int main()
{
	srand(time(NULL));
	//ios::sync_with_stdio(0); cin.tie(0);
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		
		vector<int> aa;
		min1=1; max1=10;
		n=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		//cin>>n;
		file<<n<<"\n";
		
		min1=50; max1=500;
		for(int i=0;i<n;i++)
		{
			int ans=0;
			string s="";
			stack<bool> st;
			
			s_size=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			for(int j=0;j<s_size;j++)
			{
				a=rand()%(max1-min1+1)+min1;
				if(a%3==0) s+=".";
				else if(a%3==1) s+="p";
				else s+="q";
			}
			//cin>>s;
			file<<s<<"\n";
			
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
			//cout<<ans<<"\n";
			aa.push_back(ans);
		}
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=0;i<aa.size();i++)
		{
			file<<aa[i]<<"\n";
		}
		file.close();
	} 
}

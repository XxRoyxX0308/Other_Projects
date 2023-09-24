#include<bits/stdc++.h>
using namespace std;

fstream file;
int max1,min1;

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		
		int n,m,o;
		string a;
		set<string> st;
		
		min1=100; max1=300;
		n=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		file<<n<<endl;
		//cin>>n;
		
		for(int i=0;i<n;i++)
		{
			a="";
			min1=1; max1=10;
			m=rand()%(max1-min1+1)+min1;
			
			min1=0; max1=25;
			for(int j=0;j<m;j++)
			{
				o=rand()%(max1-min1+1)+min1;
				a+=('a'+o);
			}
			file<<a<<" ";
			//cin>>a;
			
			if(st.count(a)) st.erase(a);
			else st.insert(a);
		}
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		for(auto &s:st)
		{
			file<<s<<" ";
			//cout<<s<<" ";
		}
		file.close();
	} 
}
 

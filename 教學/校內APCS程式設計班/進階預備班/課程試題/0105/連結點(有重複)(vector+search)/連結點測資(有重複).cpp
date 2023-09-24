#include<bits/stdc++.h>
using namespace std;

fstream file;
int n,m,a,b,c,min1,max1;
set<int> s[2010];

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		a=0;
		for(int i=0;i<2010;i++) s[i].clear();
		min1=100; max1=450;
		c=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		
		file.open(to_string(k)+".in",ios::out);
		min1=1; max1=2000;
		for(int i=0;i<c;i++)
		{
			n=rand()%(max1-min1+1)+min1;
			m=rand()%(max1-min1+1)+min1;
			
			s[n].insert(m);
			s[m].insert(n);
			
			file<<n<<" "<<m<<"\n";
		}
		file<<"EOF";
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=0;i<2010;i++) if(s[i].size()>a) {a=s[i].size(); b=i;}
		for(const auto &t:s[b]) file<<t<<" ";
		file.close();
	}
}

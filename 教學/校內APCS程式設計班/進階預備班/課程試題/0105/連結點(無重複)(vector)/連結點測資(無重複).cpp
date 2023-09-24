#include<bits/stdc++.h>
using namespace std;

fstream file;
int n,m,a,b,c,min1,max1;
vector<int> aa[100010];
map<int,int> bb[100010];

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		a=0;
		b=0; 
		for(int i=0;i<100010;i++)
		{
			bb[i].clear();
			aa[i].clear();
		}
		
		min1=100; max1=1000;
		c=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		
		file.open(to_string(k)+".in",ios::out);
		
		min1=1; max1=2000;
		for(int i=0;i<c;i++)
		{
			n=rand()%(max1-min1+1)+min1;
			m=rand()%(max1-min1+1)+min1;
			
			if(bb[n][m]!=1)
			{
				aa[n].push_back(m);
				aa[m].push_back(n);
				file<<n<<" "<<m<<"\n";
			}
			bb[n][m]=1;
			bb[m][n]=1;
		}
		file<<"EOF";
		file.close();
		
		for(int i=0;i<100010;i++)
		{
			if(aa[i].size()>a)
			{
				a=aa[i].size();
				b=i;
			}
		}
		
		file.open(to_string(k)+".out",ios::out);
		sort(aa[b].begin(),aa[b].end(),greater<int>());
		int j=aa[b].size();
		for(int i=0;i<j;i++)
		{
			file<<aa[b][i]<<" ";
		}
		file.close();
	}
}

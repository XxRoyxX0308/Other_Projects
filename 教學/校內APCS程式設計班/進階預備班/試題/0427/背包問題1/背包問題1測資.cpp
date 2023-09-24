#include<bits/stdc++.h>
using namespace std;

long long n,m,a,b,aa[100][100010],bb[100][2];
fstream file;
long long min1,max1;

int main()
{
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		min1=1; max1=100;
		n=rand()%(max1-min1+1)+min1;
		min1=0; max1=100000;
		m=rand()%(max1-min1+1)+min1;
		file<<n<<" "<<m<<endl;
		//cin>>n>>m;
		
		min1=0; max1=100000;
		for(long long i=1;i<=n;i++)
		{
			a=rand()%(max1-min1+1)+min1;
			b=rand()%(max1-min1+1)+min1;
			file<<a<<" "<<b<<endl; 
			//cin>>a>>b;
			
			bb[i][0]=a;
			bb[i][1]=b;
		}
		file.close();
		
		for(long long i=1;i<=n;i++)
		{
			for(long long j=0;j<=m;j++)
			{
				if(bb[i][0]<=j) aa[i][j]=max(bb[i][1]+aa[i-1][j-bb[i][0]],aa[i-1][j]);
				else aa[i][j]=aa[i-1][j];
			} 
		}
		
		file.open(to_string(k)+".out",ios::out);
		file<<aa[n][m];
		//cout<<aa[n][m];
		file.close();
	}
}

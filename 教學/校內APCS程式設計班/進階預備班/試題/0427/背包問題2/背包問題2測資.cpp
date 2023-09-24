#include<bits/stdc++.h>
using namespace std;

long long n,m,a,b,aa[2][2000010],bb[1000010][2];
fstream file;
long long min1,max1;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		min1=1; max1=150;
		n=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		min1=0; max1=150;
		m=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		file<<n<<" "<<m<<endl;
		//cin>>n>>m;
		
		min1=0; max1=150;
		for(long long i=1;i<=n;i++)
		{
			a=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			b=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			file<<a<<" "<<b<<endl; 
			//cin>>a>>b;
			
			bb[i][0]=a;
			bb[i][1]=b;
		}
		file.close();
		
		for(long long i=0;i<=m;i++) aa[0][i]=0;
		
		for(long long i=1;i<=n;i++)
		{
			for(long long j=bb[i][0];j<=m;j++)
			{
				aa[1][j]=max(bb[i][1]+aa[0][j-bb[i][0]],aa[0][j]);
			}
			for(int j=bb[i][0];j<=m;j++)
			{
				aa[0][j]=aa[1][j];
			}
		}
		
		file.open(to_string(k)+".out",ios::out);
		file<<aa[0][m];
		//cout<<aa[0][m];
		file.close();
	}
}

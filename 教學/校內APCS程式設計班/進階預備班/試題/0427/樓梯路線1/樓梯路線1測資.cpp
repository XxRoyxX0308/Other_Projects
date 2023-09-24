#include<bits/stdc++.h>
using namespace std;

long long n,m,aa[110][110];
fstream file;
long long min1,max1;

int main()
{
	srand(time(NULL));

	for(int i=0;i<=20;i++) aa[i][0]=1;
	for(int j=0;j<=20;j++) aa[0][j]=1;
	
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++)
		{
			aa[i][j]=aa[i-1][j]+aa[i][j-1];
		}
	}
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		min1=1; max1=20;
		n=rand()%(max1-min1+1)+min1;
		m=rand()%(max1-min1+1)+min1;
		file<<n<<" "<<m;
		//cin>>n>>m;
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		file<<aa[n-1][m-1];
		cout<<aa[n-1][m-1]<<endl;
		file.close();
	}
}

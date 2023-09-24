#include<bits/stdc++.h>
using namespace std;

long long n,m,aa[1000][1000];
fstream file;
long long min1,max1;

int main()
{
	srand(time(NULL));
 
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		min1=1; max1=1000;
		n=rand()%(max1-min1+1)+min1;
		m=rand()%(max1-min1+1)+min1;
		file<<n<<" "<<m<<endl;
		//cin>>n>>m;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				aa[i][j]=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
				file<<aa[i][j]<<" ";
				//cin>>aa[i][j];
			}
			file<<endl;
		}
		file.close();
		for(int i=1;i<n;i++) aa[i][0]+=aa[i-1][0];
		for(int j=1;j<m;j++) aa[0][j]+=aa[0][j-1];
		for(int i=1;i<n;i++) for(int j=1;j<m;j++) aa[i][j]+=min(aa[i-1][j],aa[i][j-1]);
	
		file.open(to_string(k)+".out",ios::out);
		file<<aa[n-1][m-1];
		//cout<<aa[n-1][m-1];
		file.close();
	} 
}

#include<bits/stdc++.h>
using namespace std;

long long dp[100];
fstream file,file1;
long long min1,max1;

int main()
{
	srand(time(NULL));
	
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=80;i++) dp[i]=dp[i-1]+dp[i-2];
		
	for(int k=1;k<=20;k++)
	{	
		int n,a;
		
		file.open(to_string(k)+".in",ios::out);
		min1=0; max1=1000000;
		n=rand()%(max1-min1+1)+min1;
		//cin>>n;
		file<<n<<endl;
		
		file1.open(to_string(k)+".out",ios::out);
		for(int i=0;i<n;i++)
		{
			min1=0; max1=80;
			a=rand()%(max1-min1+1)+min1;
			//cin>>a;
			file<<a<<endl;
			
			file1<<dp[a]<<"\n";
			//cout<<dp[a]<<"\n";
		}
		
		file.close();
		file1.close();
	}
}

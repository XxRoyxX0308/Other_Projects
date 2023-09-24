#include<bits/stdc++.h>
using namespace std;

long long coins[6]={1,3,7,13,97,211},aa[1000010];
fstream file,file1;
long long min1,max1;

int main()
{
	srand(time(NULL));
	
	aa[0]=1;
	for(int i=0;i<6;i++) for(int j=coins[i];j<=1000000;j++) aa[j]+=aa[j-coins[i]];
	
	for(int k=1;k<=20;k++)
	{
		int n,a;
		
		file.open(to_string(k)+".in",ios::out);
		min1=0; max1=1000000;
		n=rand()%(max1-min1+1)+min1;
		file<<n<<"\n";
		//cin>>n;
		
		//min1=0; max1=10;
		file1.open(to_string(k)+".out",ios::out);
		for(int i=0;i<n;i++)
		{
			a=rand()%(max1-min1+1)+min1;
			file<<a<<"\n";
			//cin>>a;
			
			file1<<aa[a]<<"\n";
			//cout<<aa[a]<<"\n";
		}
		
		file.close();
		file1.close();
	} 
}

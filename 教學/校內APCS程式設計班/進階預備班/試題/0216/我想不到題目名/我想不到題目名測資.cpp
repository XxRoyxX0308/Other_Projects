#include<bits/stdc++.h>
using namespace std;

fstream file;
long long n,k,aa[2010],bb[2010][2010],ans,max1,min1;

int main()
{
	srand(time(NULL));
	
	for(int kk=1;kk<=20;kk++)
	{
		ans=-1000000000000000;
		
		file.open(to_string(kk)+".in",ios::out);
		min1=2; max1=2000;
		n=rand()%(max1-min1+1)+min1;
		min1=1; max1=n-1;
		k=rand()%(max1-min1+1)+min1;
		//cin>>n>>k;
		file<<n<<" "<<k<<endl;
		
		min1=-100; max1=100;
		//for(int i=0;i<n;i++) cin>>aa[i];
		for(int i=0;i<n;i++)
		{
			aa[i]=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			file<<aa[i]<<" ";
		}
		file.close();
		
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) bb[i][j]=aa[i]*aa[j];
		
		for(int i=1;i<n-k+1;i++)
		{
			long long an=0,j;
			for(j=0;j<k;j++)
			{
				an+=bb[i+j][j];
			}
			ans=max(ans,an);
			//cout<<an<<endl;
			
			for(int ii=i+k;ii<n;ii++,j++)
			{
				an+=bb[ii][j]-bb[ii-k][j-k];
				ans=max(ans,an);
				//cout<<ii<<" "<<j<<" "<<an<<endl;
			}
		}
		for(int i=1;i<n-k+1;i++)
		{
			long long an=0,j;
			for(j=0;j<k;j++)
			{
				an+=bb[j][i+j];
			}
			ans=max(ans,an);
			//cout<<an<<endl;
			
			for(int ii=i+k;ii<n;ii++,j++)
			{
				an+=bb[j][ii]-bb[j-k][ii-k];
				ans=max(ans,an);
				//cout<<j<<" "<<ii<<" "<<an<<endl;
			}
		}
		file.open(to_string(kk)+".out",ios::out);
		//cout<<ans;
		file<<ans;
		file.close();
	}
}

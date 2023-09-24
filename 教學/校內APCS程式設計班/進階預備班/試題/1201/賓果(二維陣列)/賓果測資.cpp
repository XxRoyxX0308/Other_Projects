#include<bits/stdc++.h>
using namespace std;

fstream file;
long long min1,max1;
vector<int> bb;

int aa[21][21],n,m,a,ans;

int main()
{
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		min1=4,max1=20;
		n=rand()%(max1-min1+1)+min1;
		min1=n; max1=n*n;
		m=rand()%(max1-min1+1)+min1;
		
		file.open(to_string(k)+".in",ios::out);
		file<<n<<" "<<m<<"\n";
		
		for(int i=1;i<=n*n;i++) bb.push_back(i);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				min1=0; max1=bb.size()-1;
				int x=rand()%(max1-min1+1)+min1;
				aa[i][j]=bb[x];
				file<<bb[x]<<" ";
				bb.erase(bb.begin()+x);
			}
			file<<"\n";
		}
		
		bb.clear();
		for(int i=1;i<=n*n;i++) bb.push_back(i);
		
		for(int kk=0;kk<m;kk++)
		{
			min1=0; max1=bb.size()-1;
			int x=rand()%(max1-min1+1)+min1;
			a=bb[x];
			file<<bb[x]<<" ";
			bb.erase(bb.begin()+x);
			
			for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a==aa[i][j]) aa[i][j]=0;
		}
		file.close();
		
		int x1=0,y1=0;
		for(int i=0;i<n;i++)
		{
			int x=0,y=0;
			for(int j=0;j<n;j++)
			{
				if(aa[i][j]==0) x++;
				if(aa[j][i]==0) y++;
			}
			if(x==n) ans++;
			if(y==n) ans++;
			
			if(aa[i][i]==0) x1++;
			if(aa[i][n-i-1]==0) y1++;
		}
		if(x1==n) ans++;
		if(y1==n) ans++;
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				file<<aa[i][j]<<" ";
			}
			file<<"\n";
		}
		file<<ans<<"\n";
		
		file.close();
		bb.clear();
		
		if(ans==0 and(k%2==0 or k%3==0)) k--;
		ans=0; 
	}
}

#include<bits/stdc++.h>
using namespace std;

fstream file;
int n,m,aa[110][110],mina=1000010,x,y,xx[4]={1,-1,0,0},yy[4]={0,0,1,-1},a,xa,ya,ans,min1,max1;

int main()
{
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		set<int> s;
		ans=0;
		mina=1000010;
		
		file.open(to_string(k)+".in",ios::out);
		min1=0; max1=100;
		n=rand()%(max1-min1+1)+min1;
		m=rand()%(max1-min1+1)+min1;
		//cin>>n>>m;
		file<<n<<" "<<m<<endl;
		
		mina=1000010;
		min1=1; max1=1000;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
				if(s.find(a)!=s.end()) 
				{
					cout<<a<<endl;
					j--;
					continue;
				}
				s.insert(a);
				file<<a<<" ";
				aa[i][j]=a;
				//cin>>aa[i][j];
				if(mina>aa[i][j])
				{
					mina=aa[i][j];
					x=i;
					y=j; 
				} 
			}
			file<<endl;
		}
		ans+=aa[x][y];
		aa[x][y]=-1;
		file.close();
		
		while(true)
		{
			a=1000000;
			xa=0;
			for(int i=0;i<4;i++)
			{
				if(x+xx[i]>0 and x+xx[i]<n+1 and y+yy[i]>0 and y+yy[i]<m+1 and aa[x+xx[i]][y+yy[i]]>=0)
				{
					if(aa[x+xx[i]][y+yy[i]]<a)
					{
						a=aa[x+xx[i]][y+yy[i]];
						xa=x+xx[i];
						ya=y+yy[i];
					}
				}
			}
			
			if(xa) ans+=aa[xa][ya];
			else break;
			aa[xa][ya]=-1;
			x=xa;
			y=ya;
		}
		file.open(to_string(k)+".out",ios::out);
		//cout<<ans;
		file<<ans;
		file.close();
	} 
}

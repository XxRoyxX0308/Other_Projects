#include<bits/stdc++.h>
using namespace std;

fstream file,file1;
int min1,max1;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		
		set<int> st[20010];
		vector<int> vt;
		int n,m,a,b;
		cout<<"!";
		min1=1; max1=10000;
		n=rand()%(max1-min1+1)+min1;
		m=rand()%(max1-min1+1)+min1; 
		//cin>>n>>m;
		file<<n<<" "<<m<<"\n";
		
		min1=1; max1=20000;
		for(int i=0;i<n;i++)
		{
			a=rand()%(max1-min1+1)+min1;
			b=rand()%(max1-min1+1)+min1;
			//cin>>a>>b;
			//cout<<a<<"¡@"<<b<<endl;
			if(a==b)
			{
				i--;
				continue;
			}
			file<<a<<" "<<b<<"\n";
			//cout<<a<<"¡@"<<b<<endl;
			st[a].insert(b);
			st[b].insert(a);
			
			vt.push_back(a);
			vt.push_back(b);
		}
		
		file1.open(to_string(k)+".out",ios::out);
		min1=0; max1=vt.size();
		for(int i=0;i<m;i++)
		{
			a=rand()%(max1-min1+1)+min1;
			a=vt[a];
			file<<a<<"\n";
			
			for(auto j=st[a].begin();j!=st[a].end();j++)
			{
				//cout<<*j<<" ";
				file1<<*j<<" ";
			}
			//cout<<"\n";
			file1<<"\n";
		}
		file.close();
		file1.close();
	} 
}

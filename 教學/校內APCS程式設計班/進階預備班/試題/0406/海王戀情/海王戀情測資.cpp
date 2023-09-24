#include<bits/stdc++.h>
using namespace std;

fstream file,file1;
int min1,max1;

int main()
{
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		min1=1; max1=1000;
		int n,n1=rand()%(max1-min1+1)+min1,n2,a,day=0;
		map<string,int> m,m1;
		vector<string> v;
		string s;
		
		for(int i1=0;i1<n1;i1++)
		{
			min1=0; max1=10;
			n=rand()%(max1-min1+1)+min1;
			file<<n<<" ";
			
			for(int i=0;i<n;i++)
			{
				min1=0; max1=3;
				n2=rand()%(max1-min1+1)+min1;
				if(!n2 and !v.empty())
				{
					min1=0; max1=v.size()-1;
					n2=rand()%(max1-min1+1)+min1;
					s=v[n2];
				}
				else
				{
					s="";
					min1=1; max1=12;
					n2=rand()%(max1-min1+1)+min1;
					min1=0; max1=25;
					for(int j=n2;j>=0;j--)
					{
						n2=rand()%(max1-min1+1)+min1;
						s+=(n2+'a');
					}
					if(m1[s])
					{
						i--;
						continue;
					}
					m1[s]=1;
					v.push_back(s);
				}
				
				min1=0; max1=100;
				a=rand()%(max1-min1+1)+min1;
				//cin>>s>>a;
				
				file<<s<<" "<<a<<" ";
				
				if(m[s]>day) m[s]+=a;
				else m[s]=day+a;
			}
			file<<endl;
			day++;
		}
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		for(auto &mm:m) if(mm.second>day) file<<mm.first<<"\n";
		file.close();
	}
}

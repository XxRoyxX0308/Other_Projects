#include<bits/stdc++.h>
using namespace std;

vector<int> abc,aa;
fstream file;
int aa1[1000010],ans;

int main()
{
	srand(time(NULL));
	int min=0,max=0,n=100,x,y;
	//x=rand()%(max-min+1)+min;
	
	for(int k=1;k<=2;k++)
	{
		if(k==11) n=10000;
		else if(k==16) n=1000000;
		
		max=n;
		ans=0;
		for(int i=1;i<=n;i++) abc.push_back(i);
		
		while(max!=0)
		{
			x=rand()%(max-min+1)+min;
			if(x==0) continue;
			for(int i=0;i<x;i++)
			{
				y=rand()%(max-1-min+1)+min;
				aa.push_back(abc[y]);
				abc.erase(abc.begin()+y);
				max--;
			}
			/*
			cout<<x<<"!!!!";
			for(int i=0;i<aa.size();i++) cout<<aa[i]<<" ";
			cout<<"\n";
			*/
			//for(int i=0;i<aa.size();i++) aa1[aa[i]]=aa[aa.size()-i-1];
			sort(aa.begin(),aa.end());
			aa.push_back(aa[0]);
			for(int i=0;i<aa.size()-1;i++) aa1[aa[i]]=aa[i+1];
			ans++;
			aa.clear();
		}
		
		file.open(to_string(k)+".in",ios::out);
		file<<n<<"\n";
		for(int i=1;i<=n;i++) file<<aa1[i]<<" ";
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		file<<ans<<"\n";
		file.close();
	}
}

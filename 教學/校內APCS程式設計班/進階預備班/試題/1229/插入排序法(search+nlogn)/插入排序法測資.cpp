#include<bits/stdc++.h>
using namespace std;

int n,m,a,min1,max1;
vector<int> aa;
fstream file;

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		aa.clear();
		min1=1000000; max1=2000000;
		n=(rand()%(max1-min1+1)+min1);
		file.open(to_string(k)+".in",ios::out);
		file<<n<<"\n";
		
		min1=-1000; max1=1000;
		for(int i=0;i<n;i++)
		{
			a=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			aa.push_back(a);
			file<<a<<" ";
		}
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		sort(aa.begin(),aa.end());
		for(int i=0;i<aa.size();i++) file<<aa[i]<<" ";
		file.close();
	}
}

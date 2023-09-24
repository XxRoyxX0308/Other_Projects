#include<bits/stdc++.h>
using namespace std;

fstream file;

long long f(long long x)
{
	if(x==0) return 1;
	else return f(x/2)+x;
}

int main()
{
	srand(time(NULL));
	long long min=1,max=1e4,n;
	int t=10000;
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		file<<t<<"\n";
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		file.close();
		
		if(k==11) t=100000;
		for(int i=0;i<t;i++)
		{
			n=(rand()%(max-min+1)+min)*(rand()%(max-min+1)+min)*(rand()%(max-min+1)+min)*(rand()%(max-min+1)+min);
			file.open(to_string(k)+".in",ios::app);
			file<<n<<"\n";
			file.close();
			
			file.open(to_string(k)+".out",ios::app);
			file<<f(n)<<"\n";
			file.close();
		}
	}
}

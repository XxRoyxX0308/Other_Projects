#include<bits/stdc++.h>
using namespace std;

fstream file;

int aaa(int N)
{
	if(N>=101) return N-10;
	else return aaa(aaa(N+11));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	srand(time(NULL));
	long long min=-100,max=300,a,x,t=10000;
	
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		file.close();
		
		//if(k==11) t=250000;
		//else if(k==16) t=1000000;
		for(int i=0;i<t;i++)
		{
			x=(rand()%(max-min+1)+min)*(rand()%(max-min+1)+min);
			if(x==0) continue;
			
			file.open(to_string(k)+".in",ios::app);
			file<<x<<"\n";
			file.close();
			
			if(x==0) break;
			file.open(to_string(k)+".out",ios::app);
			if(x>101) file<<"f91("<<x<<") = "<<x-10<<"\n";
			else file<<"f91("<<x<<") = 91"<<"\n";
			file.close();
			//cout<<"f91("<<a<<") = "<<aaa(a)<<"\n";
		}
		
		file.open(to_string(k)+".in",ios::app);
		file<<0;
		file.close();
	}
}

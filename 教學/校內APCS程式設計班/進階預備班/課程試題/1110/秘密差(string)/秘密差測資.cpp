#include<bits/stdc++.h>
using namespace std;

ofstream file;

int main()
{
	int m=4;
	srand(time(NULL));             //!!!!!!
	long long min=0,max=9;         //!!!!!!
	
	for(int k=1;k<=20;k++)
	{
		if(k==6) m=9;
		if(k==16) m=1000;
		
		int b;
		long long x=0,y=0;
		string a="";
		for(int j=0;j<m;j++)
		{
			b=rand()%(max-min+1)+min;
			a+=to_string(b); 
		}
		
		for(int i=0,j=1;i<a.size(),j<a.size();i+=2,j+=2)
		{
			x+=a[i]-'0';
			y+=a[j]-'0'; 
		}
		if(a.size()%2) x+=a[a.size()-1]-'0';
		
		file.open(to_string(k)+".in",ios::out);
		file<<a;
		file.close();
		file.open(to_string(k)+".out",ios::out);
		file<<abs(y-x);
		file.close();
	}
}

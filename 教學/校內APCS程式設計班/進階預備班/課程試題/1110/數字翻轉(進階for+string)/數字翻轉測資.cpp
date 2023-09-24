#include<bits/stdc++.h>
using namespace std;

ofstream file;
int r,x;
string a;

int rrr()
{
	bool b=0;
	file.open(to_string(x)+".out",ios::out);
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]-'0') b=1;
		if(b)
		{
			file<<a[i];
			//cout<<a[i];
		}
	}
	file.close();
	if(!b)
	{
		cout<<"0";
		file.open(to_string(x)+".out",ios::out);
		file<<0;
		file.close();
	}
	cout<<endl<<endl;
}


int main()
{
	srand(time(NULL));              //!!!!!!
	long long min=0,max=9;         //!!!!!!
	
	for(int i=1;i<=10;i++)
	{
		x=i;
		a="";
		for(int j=0;j<6;j++)
		{
			r=rand()%(max-min+1)+min;   //!!!!!!
			a+=to_string(r);
		}
		file.open(to_string(x)+".in",ios::out);
		file<<a;
		file.close();
		cout<<a<<endl;
		rrr();
	}
	
	
	for(int i=11;i<=15;i++)
	{
		x=i;
		a="";
		for(int j=0;j<18;j++)
		{
			r=rand()%(max-min+1)+min;   //!!!!!!
			a+=to_string(r);
		}
		file.open(to_string(x)+".in",ios::out);
		file<<a;
		file.close();
		cout<<a<<endl;
		rrr();
	}
	
	
	for(int i=15;i<=20;i++)
	{
		x=i;
		a="";
		for(int j=0;j<1000000;j++)
		{
			r=rand()%(max-min+1)+min;   //!!!!!!
			a+=to_string(r);
		}
		file.open(to_string(x)+".in",ios::out);
		file<<a;
		file.close();
		//cout<<a<<endl;
		rrr();
	}
}

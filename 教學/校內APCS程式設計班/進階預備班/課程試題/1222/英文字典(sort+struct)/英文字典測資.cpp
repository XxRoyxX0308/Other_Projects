#include<bits/stdc++.h>
using namespace std;

fstream file;
int a,z=0,min1,max1;
map<string,bool> data;

struct tt
{
	int x[30];
	string s;
}mystruct[100010];

bool q(tt x,tt y)
{
	z++;
	if(x.x[z]!=y.x[z])
	{
		int x1=x.x[z],y1=y.x[z];
		z=0;
		return x1<y1;
	}
	else return q(x,y);
}

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		for(int i=0;i<100010;i++)
		{
			mystruct[i].s="";
			for(int j=0;j<30;j++) mystruct[i].x[j]=0;
		}
		data.clear();
		
		min1=1; max1=100000;
		a=rand()%(max1-min1+1)+min1;
		
		file.open(to_string(k)+".in",ios::out);
		file<<a<<"\n";
		
		for(int i=0;i<a;i++)
		{
			min1=1; max1=20;
			int strsize=rand()%(max1-min1+1)+min1;
			
			min1=1; max1=26;
			for(int j=1;j<=strsize;j++)
			{
				mystruct[i].x[j]=rand()%(max1-min1+1)+min1;
				mystruct[i].s+=(mystruct[i].x[j]+97-1);
			}
			
			if(data[mystruct[i].s])
			{
				mystruct[i].s="";
				for(int j=0;j<30;j++) mystruct[i].x[j]=0;
				i--;
			}
			else
			{
				data[mystruct[i].s]=1;
				file<<mystruct[i].s<<"\n";
			}
		}
		file.close();
		
		z=0;
		sort(mystruct,mystruct+a,q);
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=0;i<a;i++)
		{
			file<<mystruct[i].s<<"\n";
		}
		file.close();
	}
}

#include<bits/stdc++.h>
using namespace std;

fstream file; 
struct tt
{
	long long n,m;
}mystruct[100010];
int a,aa[100010],bb[100010],max1,min1;

bool q(tt a,tt b)
{
	if(a.n!=b.n) return(a.n<b.n);
	else return(a.m>b.m);
}

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		min1=1; max1=100000;
		a=rand()%(max1-min1+1)+min1;
		file.open(to_string(k)+".in",ios::out);
		file<<a<<"\n";
		
		min1=-1e3; max1=1e3;
		for(int i=0;i<a;i++)
		{
			mystruct[i].n=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			mystruct[i].m=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			file<<mystruct[i].n<<" "<<mystruct[i].m<<"\n";
			aa[i]=mystruct[i].n;
			bb[i]=mystruct[i].m;
		}
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		//sort(aa,aa+a);
		//for(int i=a-1;i>=0;i--) file<<aa[i]<<" ";
		//file<<"\n";
		//sort(bb,bb+a,greater<int>());
		//for(int i=a-1;i>=0;i--) file<<bb[i]<<" ";
		//file<<"\n";
		sort(mystruct,mystruct+a,q);
		for(int i=0;i<a;i++) file<<mystruct[i].n<<" "<<mystruct[i].m<<"\n";
		file.close();
	}
}

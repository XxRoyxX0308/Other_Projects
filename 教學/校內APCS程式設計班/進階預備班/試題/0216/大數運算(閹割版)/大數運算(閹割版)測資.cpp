#include<bits/stdc++.h>
using namespace std;

fstream file;
string a,b,c;
int aa[1000010],bb[1000010],al,bl,cl,min1,max1;
bool t;

int main()
{
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		for(int i=0;i<1000010;i++)
		{
			aa[i]=0;
			bb[i]=0;
		}
		t=0;
		a="";
		b="";
		
		file.open(to_string(k)+".in",ios::out);
		
		min1=1; max1=1000;
		al=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		bl=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		while(al<bl) bl=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
		
		min1=0; max1=9;
		for(int i=0;i<al;i++) a+=to_string(rand()%(max1-min1+1)+min1);
		for(int i=0;i<bl;i++) b+=to_string(rand()%(max1-min1+1)+min1);
		
		min1=0; max1=1;
		cl=rand()%(max1-min1+1)+min1;
		if(cl) c="+";
		else c="-";
		
		file<<a<<" "<<c<<" "<<b<<endl;
		//cin>>a>>c>>b;
		
		file.close();
		
		for(int i=0;i<a.size();i++) aa[i]=a[a.size()-i-1]-'0';
		for(int i=0;i<b.size();i++) bb[i]=b[b.size()-i-1]-'0';
		
		if(c=="+")
		{
			for(int i=0;i<a.size();i++)
			{
				aa[i]+=bb[i];
				if(aa[i]>=10) 
				{
					aa[i]-=10;
					aa[i+1]+=1;
				}
			}
		}
		else if(c=="-")
		{
			for(int i=0;i<a.size();i++)
			{
				aa[i]-=bb[i];
				if(aa[i]<0) 
				{
					aa[i]+=10;
					aa[i+1]-=1;
				}
			}
		}
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=1000001;i>=0;i--)
		{
			if(aa[i]==0 and !t) continue;
			else t=1;
			file<<aa[i];
			//cout<<aa[i];
		}
		file.close();
	} 
}

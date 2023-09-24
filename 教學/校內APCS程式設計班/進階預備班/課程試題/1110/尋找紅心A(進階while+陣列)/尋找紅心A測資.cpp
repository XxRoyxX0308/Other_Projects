#include<bits/stdc++.h>
using namespace std;

ofstream file;
int aa[26],b,b1;
string a;
long long mint,maxt,r,r1,r2;

int main()
{
	for(int k=1;k<=20;k++)
	{
		file.open(to_string(k)+".in",ios::out);
		file.close();
		file.open(to_string(k)+".out",ios::out);
		file.close();
		
		srand(time(NULL));
		if(k<=10)
		{
			mint=1e2*4; maxt=1e2*5;
		}
		else
		{
			mint=1e3*3; maxt=1e3*5;
		}
		r=rand()%(maxt-mint+1)+mint;
		cout<<r<<endl;
		
		for(int j=0;j<r;j++)
		{
			a="";
			mint=1e3; maxt=1e3*5;
			r1=rand()%(maxt-mint+1)+mint;
			mint=0; maxt=127;
			for(int i=0;i<r1;i++)
			{
				r2=rand()%(maxt-mint+1)+mint;
				if(r2==10) r2++;
				a+=char(r2);
			}
			//cout<<a<<endl;
			file.open(to_string(k)+".in",ios::app);
			file<<a<<endl;
			file.close();
			
			b=0;
			b1=0;
			for(int i=0;i<26;i++) aa[i]=0;
			
			for(int i=0;i<a.size();i++)
			{
				if(a[i]>='A' and a[i]<='Z') aa[a[i]-'A']++;
				else if(a[i]>='a' and a[i]<='z') aa[a[i]-'a']++;
			}
			for(int i=0;i<26;i++)
			{
				if(b<aa[i])
				{
					b=aa[i];
					b1=i;
				}
			}
			
			//cout<<char(b1+'A')<<" "<<b<<endl;
			file.open(to_string(k)+".out",ios::app);
			file<<char(b1+'A')<<" "<<b<<endl;
			file.close();
		}
		file.open(to_string(k)+".in",ios::app);
		file<<"EOF";
		file.close();
	}
}

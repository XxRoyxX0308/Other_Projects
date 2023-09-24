#include<bits/stdc++.h>
using namespace std;

ofstream file;
long long a,a1,b,r,z;

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	srand(time(NULL));             //!!!!!!
	long long min=1,max=4;         //!!!!!!
	
	for(int i=1;i<=10;i++)
	{
		r=1e5;
		//min=1e5; max=1e6;
		//r=rand()%(max-min+1)+min;
		cout<<r<<endl;
		
		file.open(to_string(i)+".in",ios::out);
		file.close();
		file.open(to_string(i)+".out",ios::out);
		file.close();
				
		for(int j=0;j<r;j++)
		{
			min=1; max=4;
			b=rand()%(max-min+1)+min;
			
			min=0; max=1;
			z=rand()%(max-min+1)+min;
			min=1e3; max=1e3*6;
			a=rand()%(max-min+1)+min;
			if(z) a*=-1;
			
			min=0; max=1;
			z=rand()%(max-min+1)+min;
			min=1e3; max=1e3*6;
			a1=rand()%(max-min+1)+min;
			if(z) a1*=-1;
			//cout<<a<<endl<<a1<<endl;
			
			file.open(to_string(i)+".in",ios::app);
			if(b==1) file<<a<<" + "<<a1<<endl;
			else if(b==2) file<<a<<" - "<<a1<<endl;
			else if(b==3) file<<a<<" * "<<a1<<endl;
			else file<<a<<" / "<<a1<<endl;
			file.close();
			
			if(b==1)
			{
				//cout<<a+a1<<endl;
				file.open(to_string(i)+".out",ios::app);
				file<<a+a1<<endl;
				file.close();
			}
			else if(b==2)
			{
				//cout<<a-a1<<endl;
				file.open(to_string(i)+".out",ios::app);
				file<<a-a1<<endl;
				file.close();
			}
			else if(b==3)
			{
				//cout<<a*a1<<endl;
				file.open(to_string(i)+".out",ios::app);
				file<<a*a1<<endl;
				file.close();
			}
			else
			{
				//cout<<a/a1<<endl;
				file.open(to_string(i)+".out",ios::app);
				file<<a/a1<<endl;
				file.close();
			}
			//cout<<endl;
		}
	}
	
	
	
	for(int i=11;i<=20;i++)
	{
		r=1e5;
		//min=1e5; max=1e6;
		//r=rand()%(max-min+1)+min;
		cout<<r<<endl;
		
		file.open(to_string(i)+".in",ios::out);
		file.close();
		file.open(to_string(i)+".out",ios::out);
		file.close();
				
		for(int j=0;j<r;j++)
		{
			min=1; max=4;
			b=rand()%(max-min+1)+min;
			
			min=0; max=1;
			z=rand()%(max-min+1)+min;
			min=1e6; max=1e6*6;
			a=rand()%(max-min+1)+min;
			if(z) a*=-1;
			
			min=0; max=1;
			z=rand()%(max-min+1)+min;
			min=1e6; max=1e6*6;
			a1=rand()%(max-min+1)+min;
			if(z) a1*=-1;
			//cout<<a<<endl<<a1<<endl;
			
			file.open(to_string(i)+".in",ios::app);
			if(b==1) file<<a<<" + "<<a1<<endl;
			else if(b==2) file<<a<<" - "<<a1<<endl;
			else if(b==3) file<<a<<" * "<<a1<<endl;
			else file<<a<<" / "<<a1<<endl;
			file.close();
			
			if(b==1)
			{
				//cout<<a+a1<<endl;
				file.open(to_string(i)+".out",ios::app);
				file<<a+a1<<endl;
				file.close();
			}
			else if(b==2)
			{
				//cout<<a-a1<<endl;
				file.open(to_string(i)+".out",ios::app);
				file<<a-a1<<endl;
				file.close();
			}
			else if(b==3)
			{
				//cout<<a*a1<<endl;
				file.open(to_string(i)+".out",ios::app);
				file<<a*a1<<endl;
				file.close();
			}
			else
			{
				//cout<<a/a1<<endl;
				file.open(to_string(i)+".out",ios::app);
				file<<a/a1<<endl;
				file.close();
			}
			//cout<<endl;
		}
	}
}

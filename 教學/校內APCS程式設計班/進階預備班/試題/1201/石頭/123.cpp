#include<bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

ofstream file;
long long a;

/*
srand(time(NULL));
long long min=1,max=1000000;
a=rand()%(max-min+1)+min;
*/

int main()
{
	srand(time(NULL));               //!!!!!!
	long long min=1,max=1e6;         //!!!!!!
	
	for(int i=1;i<=15;i++)
	{
		a=rand()%(max-min+1)+min;
		file.open(to_string(i)+".in",ios::out);
		file<<a;
		file.close();
		cout<<a<<" "<<to_string(a).size()<<endl;
		
		file.open(to_string(i)+".out",ios::out);
		if(a%4) file<<"C";
		else file<<"L";
		file.close();
	}
	
	for(int i=16;i<=20;i++)
	{
		a=pow(rand()%(max-min+1)+min,4);
		file.open(to_string(i)+".in",ios::out);
		file<<a;
		file.close();
		cout<<a<<" "<<to_string(a).size()<<endl;
		
		file.open(to_string(i)+".out",ios::out);
		if(a%4) file<<"C";
		else file<<"L";
		file.close();
	}
}

#include<bits/stdc++.h>
using namespace std;
struct data
{
	int ax,ay,bx,by,cx,cy,dx,dy,typ;
};
int main()
{
	int n,shape[10]={};//正方形、長方形、平行四邊形、菱形、箏形
	data f[10005]; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>f[i].ax>>f[i].ay>>f[i].bx>>f[i].by>>f[i].cx>>f[i].cy>>f[i].dx>>f[i].dy;
		if(f[i].ax==f[i].dx&&f[i].ay==f[i].by&&f[i].bx==f[i].cx&&f[i].cy==f[i].dy)
		{
			if(f[i].bx-f[i].ax==f[i].ay-f[i].dy) 
			{
				f[i].typ=1;
				shape[f[i].typ]++;
			}
			else
			{
				f[i].typ=2;
				shape[f[i].typ]++;
			} 
		}
		else if(f[i].ay==f[i].by&&f[i].cy==f[i].dy&&f[i].bx-f[i].ax==f[i].cx-f[i].dx) 
		{
			f[i].typ=3;
			shape[f[i].typ]++;
		}
		else if(f[i].ax==f[i].cx&&f[i].by==f[i].dy&&(f[i].bx+f[i].dx)/2==f[i].ax)
		{
			if(f[i].ay-f[i].by==f[i].by-f[i].cy&&f[i].bx-f[i].ax==f[i].ax-f[i].dx)
			{
				f[i].typ=4;
				shape[f[i].typ]++;
			}
			else
			{
				f[i].typ=5;
				shape[f[i].typ]++;
			}
		}
		else f[i].typ=0;
	}
	for(int i=1;i<=5;i++)
	{
		if(shape[i])
		{
			if(i==1) cout<<"square: ";
			else if(i==2) cout<<"rectangle: ";
			else if(i==3) cout<<"parallelogram: "; 
			else if(i==4) cout<<"diamond: ";
			else cout<<"kite: ";
			cout<<shape[i]<<'\n';
			int k=0,ii=0;
			while(k<shape[i])
			{
				if(f[ii].typ==i)
				{
					cout<<ii+1;
					cout<<" ("<<f[ii].ax<<","<<f[ii].ay<<")";
					cout<<" ("<<f[ii].bx<<","<<f[ii].by<<")";
					cout<<" ("<<f[ii].cx<<","<<f[ii].cy<<")";
					cout<<" ("<<f[ii].dx<<","<<f[ii].dy<<")\n";
					k++;
				}
				ii++;
			}
		}
	}
	return 0;
}

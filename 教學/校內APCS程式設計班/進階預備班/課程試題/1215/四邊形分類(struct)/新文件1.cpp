#include<bits/stdc++.h>
using namespace std;
struct group
{
	long long t,xa,ya,xb,yb,xc,yc,xd,yd;
}arr[10005];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	group k;
	long long o=0,p=0,r=0,s=0,u=0,n,ab,bc,cd,ad;
	cin>>n;
	ab=sqrt((k.xa-k.xb)*(k.xa-k.xb)+(k.ya-k.yb)*(k.ya-k.yb));
	bc=sqrt((k.xc-k.xb)*(k.xc-k.xb)+(k.yc-k.yb)*(k.yc-k.yb));
	ad=sqrt((k.xa-k.xd)*(k.xa-k.xd)+(k.ya-k.yd)*(k.ya-k.yd));
	cd=sqrt((k.xd-k.xc)*(k.xd-k.xc)+(k.yd-k.yc)*(k.yd-k.yc));
	for(int i=0;i<n;i++)
	{
		cin>>k.xa>>k.ya>>k.xb>>k.yb>>k.xc>>k.yc>>k.xd>>k.yd;
		ab=sqrt((k.xa-k.xb)*(k.xa-k.xb)+(k.ya-k.yb)*(k.ya-k.yb));
		bc=sqrt((k.xc-k.xb)*(k.xc-k.xb)+(k.yc-k.yb)*(k.yc-k.yb));
		ad=sqrt((k.xa-k.xd)*(k.xa-k.xd)+(k.ya-k.yd)*(k.ya-k.yd));
		cd=sqrt((k.xd-k.xc)*(k.xd-k.xc)+(k.yd-k.yc)*(k.yd-k.yc));
		if(k.ya==k.yb&&k.yc==k.yd)
		{
			if((ab==bc&&bc==cd&&cd==ad)&&(k.ya-k.yb)*(k.yb-k.yc)==(-1)*(k.xa-k.xb)*(k.xb-k.xc))
			{
				arr[i].t=1;
				arr[i].xa=k.xa;
				arr[i].ya=k.ya;
				arr[i].xb=k.xb;
				arr[i].yb=k.yb;
				arr[i].xc=k.xc;
				arr[i].yc=k.yc;
				arr[i].xd=k.xd;
				arr[i].yd=k.yd;
				o++;
			}
			else if(ab!=bc&&(k.ya-k.yb)*(k.yb-k.yc)==(-1)*(k.xa-k.xb)*(k.xb-k.xc))
			{
				arr[i].t=2;
				arr[i].xa=k.xa;
				arr[i].ya=k.ya;
				arr[i].xb=k.xb;
				arr[i].yb=k.yb;
				arr[i].xc=k.xc;
				arr[i].yc=k.yc;
				arr[i].xd=k.xd;
				arr[i].yd=k.yd;
				p++;
			}
			else
			{
				arr[i].t=3;
				arr[i].xa=k.xa;
				arr[i].ya=k.ya;
				arr[i].xb=k.xb;
				arr[i].yb=k.yb;
				arr[i].xc=k.xc;
				arr[i].yc=k.yc;
				arr[i].xd=k.xd;
				arr[i].yd=k.yd;
				r++;
			}
		}
		else 
		{
			if((ab==bc&&bc==cd&&cd==ad))
			{
				arr[i].t=4;
				arr[i].xa=k.xa;
				arr[i].ya=k.ya;
				arr[i].xb=k.xb;
				arr[i].yb=k.yb;
				arr[i].xc=k.xc;
				arr[i].yc=k.yc;
				arr[i].xd=k.xd;
				arr[i].yd=k.yd;
				s++;
			}
			else
			{
				arr[i].t=5;
				arr[i].xa=k.xa;
				arr[i].ya=k.ya;
				arr[i].xb=k.xb;
				arr[i].yb=k.yb;
				arr[i].xc=k.xc;
				arr[i].yc=k.yc;
				arr[i].xd=k.xd;
				arr[i].yd=k.yd;
				u++;
			}
		}
	}
	if(o!=0) 
	cout<<"square: "<<o<<'\n';
	for(int j=0;j<n;j++)
	{
		if(arr[j].t==1)
		{
			cout<<j+1<<" ("<<arr[j].xa<<","<<arr[j].ya<<")"<<" ("<<arr[j].xb<<","<<arr[j].yb<<")"<<" ("<<arr[j].xc<<","<<arr[j].yc<<")"<<" ("<<arr[j].xd<<","<<arr[j].yd<<")"<<'\n';
		}
	}
	if(p!=0) 
	cout<<"rectangle: "<<p<<'\n';
	for(int j=0;j<n;j++)
	{
		if(arr[j].t==2)
		{
			cout<<j+1<<" ("<<arr[j].xa<<","<<arr[j].ya<<")"<<" ("<<arr[j].xb<<","<<arr[j].yb<<")"<<" ("<<arr[j].xc<<","<<arr[j].yc<<")"<<" ("<<arr[j].xd<<","<<arr[j].yd<<")"<<'\n';
		}
	}
	if(r!=0) 
	cout<<"parallelogram: "<<r<<'\n';
	for(int j=0;j<n;j++)
	{
		if(arr[j].t==3)
		{
			cout<<j+1<<" ("<<arr[j].xa<<","<<arr[j].ya<<")"<<" ("<<arr[j].xb<<","<<arr[j].yb<<")"<<" ("<<arr[j].xc<<","<<arr[j].yc<<")"<<" ("<<arr[j].xd<<","<<arr[j].yd<<")"<<'\n';
		}
	}
	if(s!=0) 
	cout<<"diamond: "<<s<<'\n';
	for(int j=0;j<n;j++)
	{
		if(arr[j].t==4)
		{
			cout<<j+1<<" ("<<arr[j].xa<<","<<arr[j].ya<<")"<<" ("<<arr[j].xb<<","<<arr[j].yb<<")"<<" ("<<arr[j].xc<<","<<arr[j].yc<<")"<<" ("<<arr[j].xd<<","<<arr[j].yd<<")"<<'\n';
		}
	}
	if(u!=0) 
	cout<<"kite: "<<u<<'\n';
	for(int j=0;j<n;j++)
	{
		if(arr[j].t==5)
		{
			cout<<j+1<<" ("<<arr[j].xa<<","<<arr[j].ya<<")"<<" ("<<arr[j].xb<<","<<arr[j].yb<<")"<<" ("<<arr[j].xc<<","<<arr[j].yc<<")"<<" ("<<arr[j].xd<<","<<arr[j].yd<<")"<<'\n';
		}
	}
	return 0;
}

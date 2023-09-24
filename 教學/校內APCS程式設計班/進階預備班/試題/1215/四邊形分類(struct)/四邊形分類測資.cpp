#include<bits/stdc++.h>
using namespace std;

fstream file;
int max1,min1,ouo;
struct data
{
	int ax,ay,bx,by,cx,cy,dx,dy,typ;
};

int main()
{
	srand(time(NULL));
	for(int k=1;k<=20;k++)
	{
		int n,shape[10]={};
		data f[10005];
		
		min1=1; max1=1e4;
		n=rand()%(max1-min1+1)+min1;
		
		file.open(to_string(k)+".in",ios::out);
		file<<n<<"\n";
		
		for(int i=0;i<n;i++)
		{
			min1=1; max1=5;
			ouo=rand()%(max1-min1+1)+min1;
			
			//cin>>f[i].ax>>f[i].ay>>f[i].bx>>f[i].by>>f[i].cx>>f[i].cy>>f[i].dx>>f[i].dy;
			//f[i].ax=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			//f[i].ay=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			//f[i].bx=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			//f[i].by=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			//f[i].cx=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			//f[i].cy=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			//f[i].dx=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			//f[i].dy=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			
			min1=1; max1=1e3;
			f[i].ax=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			f[i].ay=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			shape[ouo]++;
			f[i].typ=ouo;
			if(ouo==1)
			{
				if(1e8-f[i].ax<f[i].ay)
				{
					min1=f[i].ax; max1=1e8;
					int uou=rand()%(max1-min1+1)+min1;
					uou-=f[i].ax;
					
					f[i].bx=f[i].ax+uou;
					f[i].by=f[i].ay;
					
					f[i].dx=f[i].ax;
					f[i].dy=f[i].ay-uou;
					
					f[i].cx=f[i].bx;
					f[i].cy=f[i].dy;
				}
				else
				{
					min1=0; max1=f[i].ay;
					int uou=rand()%(max1-min1+1)+min1;
					
					f[i].bx=f[i].ax+uou;
					f[i].by=f[i].ay; 
					
					f[i].dx=f[i].ax;
					f[i].dy=f[i].ay-uou;
					
					f[i].cx=f[i].bx;
					f[i].cy=f[i].dy;
				}
			}
			else if(ouo==2)
			{
				min1=f[i].ax; max1=1e8;
				int uou=rand()%(max1-min1+1)+min1;
				uou-=f[i].ax;
				
				f[i].bx=f[i].ax+uou;
				f[i].by=f[i].ay;
				
				min1=0; max1=f[i].ay;
				uou=rand()%(max1-min1+1)+min1;
				
				f[i].dx=f[i].ax;
				f[i].dy=f[i].ay-uou;
				
				f[i].cx=f[i].bx;
				f[i].cy=f[i].dy;
			}
			else if(ouo==3) 
			{
				min1=f[i].ax; max1=1e8;
				int uou=rand()%(max1-min1+1)+min1;
				uou-=f[i].ax;
				
				f[i].bx=f[i].ax+uou;
				f[i].by=f[i].ay;
				
				min1=0; max1=f[i].ay;
				uou=rand()%(max1-min1+1)+min1;
				
				f[i].dx=f[i].ax;
				f[i].dy=f[i].ay-uou;
				
				f[i].cx=f[i].bx;
				f[i].cy=f[i].dy;
				
				min1=-f[i].ax; max1=f[i].ax;
				uou=rand()%(max1-min1+1)+min1;
				
				f[i].cx+=uou;
				f[i].dx+=uou;
			}
			else if(ouo==4 or ouo==5)
			{
				min1=0; max1=f[i].ay;
				int uou=rand()%(max1-min1+1)+min1;
				if(uou%2==1) uou++;
				
				f[i].cx=f[i].ax;
				f[i].cy=f[i].ay-uou;
				
				f[i].by=(f[i].ay+f[i].cy)/2;
				f[i].dy=(f[i].ay+f[i].cy)/2;
				
				min1=0; max1=f[i].ax;
				uou=rand()%(max1-min1+1)+min1;
				
				f[i].bx=f[i].ax+uou;
				f[i].dx=f[i].ax-uou;
				
				if(ouo==5)
				{
					uou=min(f[i].cy,(f[i].ay+f[i].cy)/2-f[i].cy);
					min1=-uou; max1=uou;
					
					uou=rand()%(max1-min1+1)+min1;
					f[i].ay+=uou;
					
					uou=rand()%(max1-min1+1)+min1;
					f[i].cy+=uou;
				}
			}
			else
			{
				min1=0; max1=1e3;
				f[i].bx=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
				f[i].by=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
				f[i].cx=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
				f[i].cy=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
				f[i].dx=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
				f[i].dy=(rand()%(max1-min1+1)+min1)*(rand()%(max1-min1+1)+min1);
			}
			
			file<<f[i].ax<<" "<<f[i].ay<<" "<<f[i].bx<<" "<<f[i].by<<" "<<f[i].cx<<" "<<f[i].cy<<" "<<f[i].dx<<" "<<f[i].dy<<"\n";
		}
		file.close();
		
		file.open(to_string(k)+".out",ios::out);
		for(int i=1;i<=5;i++)
		{
			if(shape[i])
			{
				if(i==1) file<<"square: ";
				else if(i==2) file<<"rectangle: ";
				else if(i==3) file<<"parallelogram: "; 
				else if(i==4) file<<"diamond: ";
				else file<<"kite: ";
				file<<shape[i]<<'\n';
				
				int kk=0,ii=0;
				while(kk<shape[i])
				{
					if(f[ii].typ==i)
					{
						file<<ii+1;
						file<<" ("<<f[ii].ax<<","<<f[ii].ay<<")";
						file<<" ("<<f[ii].bx<<","<<f[ii].by<<")";
						file<<" ("<<f[ii].cx<<","<<f[ii].cy<<")";
						file<<" ("<<f[ii].dx<<","<<f[ii].dy<<")\n";
						kk++;
					}
					ii++;
				}
			}
		}
		file.close();
	}
}

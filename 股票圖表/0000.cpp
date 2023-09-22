#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<windows.h>

using namespace std;
using namespace sf;

int second();

string b,market;
double d,d1,a1,a2,a3,a4,b1,b2,b3,b4,aa[10010],bb[10010],hhigh[1000010][2];
int a,c=200000,c1=1,k,k1=0,k2,k3=1,l,l1,l2,l3,l4,m,n=0,a10=-1,kd=500;
float h=0,h1=1000;
fstream file;
vector<string> _csv(string s);
int aaa(); //代
int aaa1(double a1,double a2,double a3,double a4); //絘猭(玡)
int aaa2(double a1,double a2,double a3,double a4); //絘猭() 
int aaa3(); //だ跋(玡)
int aaa4(); //だ跋() 
int aaa5(); //だ猭(玡)
int aaa6(); //だ猭()

int test(); //ユ
int test1(); //絘猭(ユ)
int test2(); //だ跋(ユ)
int test3(); //だ猭(ユ)

int macd01(int i);
int kd01(int i);
int macd02(int i);
int kd02(int i);

int aa1();
int aa2();
int aa3();
int aa4();
int bb1();
int bb2();
int bb3();
int bb4();

int op1(); //test
int op2(); //絘
int op3(); //だ跋
int op4(); //だ
int op5(); //秈顶だ
int op6(); //瓜 

int hhh(const void* p1, const void* p2);
int a100();

vector<string> day;
vector<float> on,off,high,low,sma12,sma26,ema12,ema26,dif,macd,osc,RSV,K,D,RSV_1,K_1,D_1,sma20,bl1,bl2,all,ee,allmacd;
vector<double> hhhigh[1000010];
vector<pair<int,int> > qu;

int qq();
bool qqsort(pair<int,int> pair_a,pair<int,int> pair_b);



RenderWindow window(VideoMode(1920,1080),market);

double o=a-950,o1=2,o2=400,o3=0,o4=1,ooff=400,omacd=500,obl=900,oKD=1000,left1=0,right1=0,leftoff=0,leftmacd=0,leftbl=0,leftKD=0,y1,movingaverage1=1,MACD1=1,bollingerband1=1,KD1=1;
Text oa,ob,oc,od,omarket,oosc;
Texture buttonT1,formulaT,buttonT2,movingaverageT,buttonT3,macdT,buttonT4,bollingerbandT,buttonT5,KDT;
Sprite buttonS1,formulaS,buttonS2,movingaverageS,buttonS3,macdS,buttonS4,bollingerbandS,buttonS5,KDS;
FloatRect buttonscale1,buttonscale2,buttonscale3,buttonscale4,buttonscale5;
Font english,chinese;
Vector2i x,y,x1;

int window1();
int window2();


int main() ////////////////////////////////////////////////////////////////////////////////////////
{
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for(int i=0;i<=10000;i++)
	{
		market=to_string(i);
		for(int j=market.size();j<4;j++) market="0"+market;
		b="STOCK_DAY_"+market+"_202208.csv";
		file.open("data/"+market+"/"+b,ios::in);
		if(file)
		{
			file.close();
			on.clear(); off.clear(); high.clear(); low.clear(); day.clear();
			RSV_1.clear(); K_1.clear(); D_1.clear();
			a=0; c=200000;
			h=0; h1=10000;
			qq();
		}
	}
	sort(qu.begin(),qu.end(),qqsort);
	
	//for(int i=1000;i<=10000;i+=c1)
	for(int i=0;i<qu.size();i=i)
	{
		//market=to_string(i);
		market=to_string(qu[i].first);
		for(int j=market.size();j<4;j++) market="0"+market;
		b="STOCK_DAY_"+market+"_202208.csv";
		file.open("data/"+market+"/"+b,ios::in);
		if(file)
		{
			file.close();
			on.clear(); off.clear(); high.clear(); low.clear(); day.clear(); 
			sma12.clear(); sma26.clear();
			ema12.clear(); ema26.clear(); dif.clear(); macd.clear(); osc.clear(); 
			RSV.clear(); K.clear(); D.clear();
			RSV_1.clear(); K_1.clear(); D_1.clear();
			sma20.clear(); bl1.clear(); bl2.clear();
			all.clear(); ee.clear(); allmacd.clear();
			d=0; d1=0;
			a=0; c=200000; k=0; k1=0; k2=0; k3=1; l=0; l1=0; l2=0; l3=0; l4=0; m=0; n=0; a10=-1;
			h=0; h1=10000;
			memset(aa,0,sizeof(aa[0]));
			memset(bb,0,sizeof(bb[0]));
			memset(hhigh,0,sizeof(hhigh[0][0])*1000010*2);
			second();
		}
		
		//if(i==999) i=9999;
		//if(i==10000) i=999;
		
		i+=c1;
		if(i==-1) i=qu.size()-1;
		if(i==qu.size()) i=0;
	}
}



int qq()
{
	for(int j=0;j<1000;j++)
	{
		if(c%100==12) c+=88;
		c++;
		b=b.replace(b.begin()+15,b.begin()+21,to_string(c));
    	string line;
    	ifstream inFile;
    	inFile.open("data/"+market+"/"+b,ios::in);
    	if(!inFile) continue;
    	getline(inFile, line);
    	getline(inFile, line);
    	getline(inFile, line);
    	while(line.size()!=7)
    	{
   		 	_csv(line);
    		getline(inFile, line);
    		a++;
    	}
    }
    
    
    
	h=0; h1=10000;
	for(int i=0;i<kd;i++)                                              //RSV=(さらΜ絃基-程ぱ程基)/(程ぱ程蔼基-程ぱ程基)
	{
		RSV_1.push_back(0);
		h=max(h,high[i]);
		h1=min(h1,low[i]);
	}
    for(int i=kd;i<a;i++)
	{
		RSV_1.push_back(((off[i]-h1)*100)/(h-h1));
		h=0;
		h1=10000;
		for(int j=0;j<kd;j++)
		{
			h=max(h,high[i-j+1]);
			h1=min(h1,low[i-j+1]);
		}
	}
	
	
	
	for(int i=0;i<8;i++) K_1.push_back(0);                               //K=2/3x(琎らK)+1/3x(さらRSV)
	K_1.push_back(50);
	for(int i=9;i<a;i++)
	{
		K_1.push_back(2*K_1[i-1]/3+RSV_1[i]/3);
	}
	
	
	
	for(int i=0;i<8;i++) D_1.push_back(0);                               //D=2/3x(琎らD)+1/3x(さらK)
	D_1.push_back(50);
	for(int i=9;i<a;i++)
	{
		D_1.push_back(2*D_1[i-1]/3+K_1[i]/3);
	}
	
	
	
	qu.push_back(make_pair(stoi(market),D_1[a-1]));
	
	
	
	fstream file_price,file_rata,file_K,file_D;                        //AI datasets
    file_price.open("datasets/price/"+market+".txt",ios::out);
    file_rata.open("datasets/rata/"+market+".txt",ios::out);
    file_K.open("datasets/K/"+market+".txt",ios::out);
    file_D.open("datasets/D/"+market+".txt",ios::out);
    for(int i=0;i<a;i++)
    {
    	file_price<<off[i]<<" ";
		if(i>0 and abs((off[i]-off[i-1])/off[i-1])<1) file_rata<<(off[i]-off[i-1])/off[i-1]<<" ";
		if(i>24) file_K<<K_1[i]<<" ";
		if(i>24) file_D<<D_1[i]<<" ";
	}
    file_price.close(); file_rata.close(); file_K.close(); file_D.close();
}



bool qqsort(pair<int,int> pair_a,pair<int,int> pair_b)
{
	return pair_a.second<pair_b.second;
}



int second() ///////////////////////////////////////////////////////////////////////////////////////
{
	for(int j=0;j<1000;j++)
	{
		if(c%100==12) c+=88;
		c++;
		b=b.replace(b.begin()+15,b.begin()+21,to_string(c));
    	string line;
    	ifstream inFile;
    	inFile.open("data/"+market+"/"+b,ios::in);
    	if(!inFile) continue;
    	getline(inFile, line);
    	getline(inFile, line);
    	getline(inFile, line);
    	while(line.size()!=7)
    	{
   		 	_csv(line);
    		getline(inFile, line);
    		a++;
    	}
    }
    
    
	
    d=0;                                                               //sma12
	for(int i=0;i<11;i++)
	{
		sma12.push_back(0);
		d+=off[i];
	}
    for(int i=11;i<a;i++)
	{
		d+=off[i];
		sma12.push_back(d/12);
		d-=off[i-11];
	}
	
	
	
	d=0;                                                               //sma26
	for(int i=0;i<25;i++)
	{
		sma26.push_back(0);
		d+=off[i];
	}
    for(int i=25;i<a;i++)
	{
		d+=off[i];
		sma26.push_back(d/26);
		d-=off[i-25];
	}
	
	
	
	for(int i=0;i<12;i++)                                              //ema12=(玡らema12x(12-1)+offx2)/(12+1)
	{
		ema12.push_back(0);
		d+=off[i];
	}
	ema12.push_back(d/12);
    for(int i=13;i<a;i++) ema12.push_back((ema12[i-1]*(12-1)+off[i]*2)/(12+1));
	
	
	
    for(int i=0;i<26;i++)                                              //ema26=(玡らema26x(26-1)+offx2)/(26+1)
	{
		ema26.push_back(0);
		d+=off[i];
	}
	ema26.push_back(d/26);
    for(int i=27;i<a;i++) ema26.push_back((ema26[i-1]*(26-1)+off[i]*2)/(26+1));
	
	
	
	for(int i=0;i<26;i++) dif.push_back(0);                            //dif=ema12-ema26
    for(int i=26;i<a;i++)
	{
		d=ema12[i]-ema26[i];
		dif.push_back(d);
	}
	
	
	
	for(int i=0;i<26;i++) macd.push_back(0);                           //macd=(玡らmacdx(9-1)+difx2)/(9+1)
	macd.push_back(0);
    for(int i=27;i<a;i++) macd.push_back((macd[i-1]*(9-1)+dif[i]*2)/(9+1));

	
	
	for(int i=0;i<26;i++) osc.push_back(0);                            //osc=dif-macd
    for(int i=26;i<a;i++)
	{
		d=dif[i]-macd[i];
		osc.push_back(d);
	}
	
	
	
	h=0; h1=10000;
	for(int i=0;i<kd;i++)                                              //RSV=(さらΜ絃基-程ぱ程基)/(程ぱ程蔼基-程ぱ程基)
	{                                                                  //ヘ玡kd
		RSV.push_back(0);
		h=max(h,high[i]);
		h1=min(h1,low[i]);
	}
    for(int i=kd;i<a;i++)
	{
		RSV.push_back(((off[i]-h1)*100)/(h-h1));
		h=0;
		h1=10000;
		for(int j=0;j<kd;j++)
		{
			h=max(h,high[i-j+1]);
			h1=min(h1,low[i-j+1]);
		}
	}
	
	
	
	for(int i=0;i<8;i++) K.push_back(0);                               //K=2/3x(琎らK)+1/3x(さらRSV)
	K.push_back(50);
	for(int i=9;i<a;i++)
	{
		K.push_back(2*K[i-1]/3+RSV[i]/3);
	}
	
	
	
	for(int i=0;i<8;i++) D.push_back(0);                               //D=2/3x(琎らD)+1/3x(さらK)
	D.push_back(50);
	for(int i=9;i<a;i++)
	{
		D.push_back(2*D[i-1]/3+K[i]/3);
	}
	
	
	/*
	/////////////////////////////////////////////////////////////////////150
	h=0; h1=10000;
	for(int i=0;i<150;i++)                                             //RSV=(さらΜ絃基-程ぱ程基)/(程ぱ程蔼基-程ぱ程基)
	{
		RSV_1.push_back(0);
		h=max(h,high[i]);
		h1=min(h1,low[i]);
	}
    for(int i=150;i<a;i++)
	{
		RSV_1.push_back(((off[i]-h1)*144)/(h-h1));
		h=0;
		h1=10000;
		for(int j=0;j<150;j++)
		{
			h=max(h,high[i-j+1]);
			h1=min(h1,low[i-j+1]);
		}
	}
	
	
	
	for(int i=0;i<8;i++) K_1.push_back(0);                             //K=2/3x(琎らK)+1/3x(さらRSV)
	K_1.push_back(50);
	for(int i=9;i<a;i++)
	{
		K_1.push_back(2*K_1[i-1]/3+RSV_1[i]/3);
	}
	
	
	
	for(int i=0;i<8;i++) D_1.push_back(0);                             //D=2/3x(琎らD)+1/3x(さらK)
	D_1.push_back(50);
	for(int i=9;i<a;i++)
	{
		D_1.push_back(2*D_1[i-1]/3+K_1[i]/3);
	}
	*/
	
	
	d=0;                                                               //sma20,bl1(sma20+2*丁琿夹非畉),bl2(sma20-2*丁琿夹非畉)
	d1=0;
	for(int i=0;i<19;i++)
	{
		sma20.push_back(0);
		bl1.push_back(0);
		bl2.push_back(0);
		d+=off[i];
	}
    for(int i=19;i<a;i++)
	{
		d+=off[i];
		sma20.push_back(d/20);
		d-=off[i-19];
		
		for(int j=0;j<20;j++)
		{
			d1+=((off[i-j]-sma20[i])*(off[i-j]-sma20[i]));
		}
		d1=sqrt(d1/20);
		bl1.push_back(sma20[i]+d1*2);
		bl2.push_back(sma20[i]-d1*2);
		d1=0;
	}
	
	
	
	day.push_back("0");
	a100();
	//op1();                                                           //箇代(闽超)
	//op6();                                                           //箇代(闽超)
	o=a-950/o1;
	window1();                                                         //跌怠 
}


	
int window1() /////////////////////////////////////////////////////////////////////////////////////
{
	window.setFramerateLimit(60);
	
	english.loadFromFile("word/SedgwickAve-Regular.ttf");
	chinese.loadFromFile("word/Maiden.ttf");
	
	oa.setFont(english);
	oa.setCharacterSize(24);
	oa.setColor(Color::Black);
	oa.setStyle(Text::Bold);
	oa.setPosition(1200,1000);
	
	ob.setFont(english);
	ob.setCharacterSize(24);
	ob.setColor(Color::Black);
	ob.setStyle(Text::Bold);
	ob.setPosition(1350,1000);
	/*                                                                 //箇代(闽超)
	oc.setFont(english);
	oc.setCharacterSize(24);
	oc.setColor(Color::Black);
	oc.setStyle(Text::Bold);
	oc.setPosition(1520,1000);
	*/
	od.setFont(english);
	od.setCharacterSize(24);
	od.setColor(Color::Black);
	od.setStyle(Text::Bold);
	od.setPosition(1660,1000);
	
	omarket.setFont(english);
	omarket.setCharacterSize(36);
	omarket.setColor(Color::Black);
	omarket.setStyle(Text::Bold);
	omarket.setPosition(1800,30);
	omarket.setString(market);
	
	oosc.setFont(english);
	oosc.setCharacterSize(24);
	oosc.setColor(Color::Black);
	oosc.setStyle(Text::Bold);
	oosc.setPosition(1770,550);
	
	buttonT1.loadFromFile("picture/button1.png");
	buttonS1.setTexture(buttonT1);
	buttonS1.setPosition(30,30);
	buttonS1.setScale(0.3,0.3);
	buttonscale1=buttonS1.getGlobalBounds();
	
	formulaT.loadFromFile("picture/そΑ.png");
	formulaS.setTexture(formulaT);
	formulaS.setPosition(66,33);
	formulaS.setScale(0.45,0.45);
	
	while(window.isOpen())
	{
		Vector2i mouseposition=Mouse::getPosition();
		Event eee;
		while(window.pollEvent(eee))
		{
			if(eee.type==Event::Closed) window.close();
			
			if(eee.type==Event::KeyPressed) 
			{
				if(eee.key.code==Keyboard::Left) o-=2;
				if(eee.key.code==Keyboard::Right) o+=2;
				if(eee.key.code==Keyboard::Up) o3+=5;
				if(eee.key.code==Keyboard::Down) o3-=5;
				
				if(eee.key.code==Keyboard::Num1)
				{
					m=2;
					op4();
				}
				if(eee.key.code==Keyboard::Num2)
				{
					m=3;
					op4();
				}
				if(eee.key.code==Keyboard::Num3)
				{
					m=4;
					op4();
				}
				if(eee.key.code==Keyboard::Num4)
				{
					m=5;
					op4();
				}
				if(eee.key.code==Keyboard::Num5)
				{
					m=6;
					op4();
				}
				if(eee.key.code==Keyboard::Num6)
				{
					m=7;
					op4();
				}
				if(eee.key.code==Keyboard::Num7)
				{
					m=8;
					op4();
				}
				if(eee.key.code==Keyboard::Num8)
				{
					m=9;
					op4();
				}
				if(eee.key.code==Keyboard::Num9)
				{
					m=10;
					op4();
				}
				
				if(eee.key.code==Keyboard::Space) op5();
				
				if(eee.key.code==Keyboard::A)
				{
					a10*=-1;
					a100();
				}
				
				if(eee.key.code==Keyboard::E)
				{
					c1=1;
					return 0;
				}
				if(eee.key.code==Keyboard::Q)
				{
					c1=-1;
					return 0;
				}
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) and left1==0 and !Keyboard::isKeyPressed(Keyboard::LShift))
			{
				x=Mouse::getPosition();
				left1=1;
			}
			if(left1==1 and eee.type==Event::MouseMoved)
			{
				y=Mouse::getPosition();
				o-=(y.x-x.x)/o1;
				x=y;
			}
			
			if(leftoff==1 and eee.type==Event::MouseMoved)
			{
				y=Mouse::getPosition();
				ooff-=(x.y-y.y);
				x=y;
			}
			
			if(leftmacd==1 and eee.type==Event::MouseMoved)
			{
				y=Mouse::getPosition();
				omacd-=(x.y-y.y);
				x=y;
			}
			
			if(leftbl==1 and eee.type==Event::MouseMoved)
			{
				y=Mouse::getPosition();
				obl-=(x.y-y.y);
				x=y;
			}
			
			if(leftKD==1 and eee.type==Event::MouseMoved)
			{
				y=Mouse::getPosition();
				oKD-=(x.y-y.y);
				x=y;
			}
			
			if(Mouse::isButtonPressed(Mouse::Right) and right1==0)
			{
				x1=Mouse::getPosition();
				right1=1;
			}
			
			if(eee.type==Event::MouseButtonReleased)
			{
				left1=0;
				leftoff=0;
				leftmacd=0;
				leftbl=0;
				leftKD=0;
				right1=0;
			}
			
			//if(Keyboard::isKeyPressed(Keyboard::LControl) and (eee.type==Event::MouseWheelScrolled)) o3-=0.2;
			
			//if(Keyboard::isKeyPressed(Keyboard::LShift) and eee.mouseWheelScroll.delta==1) o2-=20;
			if(Keyboard::isKeyPressed(Keyboard::LControl) and eee.mouseWheelScroll.delta==1) o4+=0.2;
			else if(/*eee.mouseWheelScroll.wheel==Mouse::VerticalWheel and */eee.mouseWheelScroll.delta==1) o3+=5;
			
			//if(Keyboard::isKeyPressed(Keyboard::LShift) and eee.mouseWheelScroll.delta==-1) o2+=20;
			if(Keyboard::isKeyPressed(Keyboard::LControl) and eee.mouseWheelScroll.delta==-1) o4-=0.2;
			else if(/*eee.mouseWheelScroll.wheel==Mouse::VerticalWheel and */eee.mouseWheelScroll.delta==-1) o3-=5;
			
			if(buttonscale1.contains(mouseposition.x,mouseposition.y-25) and Mouse::isButtonPressed(Mouse::Left))
			{
				window2();
				return 0; 
			}
		}
		window.clear(Color::White);
		
		if(o3>0)
		{
			o1+=0.02*o1;
			o+=(double)mouseposition.x/50/o1;
			o3-=1;
		}
		if(o3<0)
		{
			o1-=0.02*o1;
			o-=(double)mouseposition.x/50/o1;
			o3+=1;
		}
		
		if(o>a-1900/o1) o=a-1900/o1;
		if(o<1) o=1;
		if(o1<0.8) o1=0.8;
		
		VertexArray mouse(Lines, 2);
		VertexArray linex(Lines, 2);
		
		VertexArray off1(Lines, a*2);
		for(int i=o;i<a-1;i++)
		{
			off1[i*2].position = Vector2f((i-o)*o1, ooff-off[i]*o4);
			off1[i*2+1].position = Vector2f((i-o+1)*o1, ooff-off[i+1]*o4);
			if(off[i]<off[i+1])
			{
				off1[i*2].color = Color(255,0,0);
				off1[i*2+1].color = Color(255,0,0);
			}
			else
			{
				off1[i*2].color = Color(0,255,0);
				off1[i*2+1].color = Color(0,255,0);
			}
			
			if((i-o+1)*o1-o1/2<=mouseposition.x and (i-o+1)*o1+o1/2>=mouseposition.x)
			{
				mouse[0].position = Vector2f((i-o+1)*o1,mouseposition.y-2000);
				mouse[0].color = Color(0,0,0);
				mouse[1].position = Vector2f((i-o+1)*o1,mouseposition.y+2000);
				mouse[1].color = Color(0,0,0);
				
				oa.setString(day[i+1]);
				ob.setString(to_string(off[i+1]));
				//oc.setString(to_string(ee[i+1]));                    //箇代(闽超)
				oosc.setString(to_string(osc[i+1]));
				
				y1=i+1;
			
				if(ooff-off[i]*o4-10<=mouseposition.y and ooff-off[i]*o4+10>=mouseposition.y)
				{
					if(Keyboard::isKeyPressed(Keyboard::LShift) and Mouse::isButtonPressed(Mouse::Left) and leftoff==0)
					{
						x=Mouse::getPosition();
						leftoff=1;
					}
				}
				
				if(omacd-macd[i]*o4-10<=mouseposition.y and omacd-macd[i]*o4+10>=mouseposition.y and MACD1==1)
				{
					if(Keyboard::isKeyPressed(Keyboard::LShift) and Mouse::isButtonPressed(Mouse::Left) and leftmacd==0)
					{
						x=Mouse::getPosition();
						leftmacd=1;
					}
				}
				
				if((obl-sma20[i]*o4-10<=mouseposition.y and obl-sma20[i]*o4+10>=mouseposition.y) and bollingerband1==1)
				{
					if(Keyboard::isKeyPressed(Keyboard::LShift) and Mouse::isButtonPressed(Mouse::Left) and leftbl==0)
					{
						x=Mouse::getPosition();
						leftbl=1;
					}
				}
				
				if((oKD-K[i]*o4-10<=mouseposition.y and oKD-K[i]*o4+10>=mouseposition.y) and KD1==1)
				{
					if(Keyboard::isKeyPressed(Keyboard::LShift) and Mouse::isButtonPressed(Mouse::Left) and leftKD==0)
					{
						x=Mouse::getPosition();
						leftKD=1;
					}
				}
			}
		}
		
		VertexArray macd1(Lines, a*2);
		for(int i=o;i<a-1;i++)
		{
			macd1[i*2].position = Vector2f((i-o)*o1, omacd-macd[i]*o4);
			macd1[i*2].color = Color(0,0,255);
			
			macd1[i*2+1].position = Vector2f((i-o+1)*o1, omacd-macd[i+1]*o4);
			macd1[i*2+1].color = Color(0,0,255);
			
			if((i-o+1)*o1-o1/2<=x1.x and (i-o+1)*o1+o1/2>=x1.x and right1==1)
			{
				linex[0].position = Vector2f((i-o+1)*o1,x1.y-2000);
				linex[0].color = Color(180,0,0);
				linex[1].position = Vector2f((i-o+1)*o1,x1.y+2000);
				linex[1].color = Color(180,0,0);
				
				if(y1>i+1) od.setString(to_string(off[y1]/off[i+1]));
				else od.setString(to_string(off[i+1]/off[y1]));
			}
		}
		
		VertexArray osc1(Lines, a*2);
		for(int i=o;i<a-1;i++)
		{
			osc1[i*2].position = Vector2f((i-o)*o1, omacd-osc[i]*o4);
			osc1[i*2+1].position = Vector2f((i-o+1)*o1, omacd-osc[i+1]*o4);
			
			if(osc[i]>=0)
			{
				osc1[i*2].color = Color(255,0,0);
				osc1[i*2+1].color = Color(255,0,0);
			}
			else
			{
				osc1[i*2].color = Color(0,255,0);
				osc1[i*2+1].color = Color(0,255,0);
			}
		}
		
		VertexArray sma201(Lines, a*2);
		for(int i=o;i<a-1;i++)
		{
			sma201[i*2].position = Vector2f((i-o)*o1, obl-sma20[i]*o4);
			sma201[i*2].color = Color(255,0,255);
			
			sma201[i*2+1].position = Vector2f((i-o+1)*o1, obl-sma20[i+1]*o4);
			sma201[i*2+1].color = Color(255,0,255);
		}
		
		VertexArray bl11(Lines, a*2);
		for(int i=o;i<a-1;i++)
		{
			bl11[i*2].position = Vector2f((i-o)*o1, obl-bl1[i]*o4);
			bl11[i*2].color = Color(0,0,255);
			
			bl11[i*2+1].position = Vector2f((i-o+1)*o1, obl-bl1[i+1]*o4);
			bl11[i*2+1].color = Color(0,0,255);
		}
		
		VertexArray bl21(Lines, a*2);
		for(int i=o;i<a-1;i++)
		{
			bl21[i*2].position = Vector2f((i-o)*o1, obl-bl2[i]*o4);
			bl21[i*2].color = Color(0,0,255);
			
			bl21[i*2+1].position = Vector2f((i-o+1)*o1, obl-bl2[i+1]*o4);
			bl21[i*2+1].color = Color(0,0,255);
		}
		
		VertexArray K1(Lines, a*2);
		for(int i=o;i<a-1;i++)
		{
			K1[i*2].position = Vector2f((i-o)*o1, oKD-K[i]*o4);
			K1[i*2].color = Color(0,0,255);
			
			K1[i*2+1].position = Vector2f((i-o+1)*o1, oKD-K[i+1]*o4);
			K1[i*2+1].color = Color(0,0,255);
		}
		
		VertexArray D1(Lines, a*2);
		for(int i=o;i<a-1;i++)
		{
			D1[i*2].position = Vector2f((i-o)*o1, oKD-D[i]*o4);
			D1[i*2].color = Color(255,0,0);
			
			D1[i*2+1].position = Vector2f((i-o+1)*o1, oKD-D[i+1]*o4);
			D1[i*2+1].color = Color(255,0,0);
		}
		/*                                                             //箇代(闽超) 
		VertexArray all1(Lines, a*2);
		for(int i=o;i<a;i++)
		{
			if(all[i]>0)
			{
				all1[i*2].position = Vector2f((i-o)*o1, all[i]+2000);
				all1[i*2].color = Color(0,255,0);
				
				all1[i*2+1].position = Vector2f((i-o)*o1, all[i]-2000);
				all1[i*2+1].color = Color(0,255,0);
			}
			else if(all[i]<0)
			{
				all1[i*2].position = Vector2f((i-o)*o1, -all[i]+2000);
				all1[i*2].color = Color(255,0,0);
				
				all1[i*2+1].position = Vector2f((i-o)*o1, -all[i]-2000);
				all1[i*2+1].color = Color(255,0,0);
			}
			else
			{
				all1[i*2].position = Vector2f((i-o)*o1, 5000-all[i]);
				all1[i*2].color = Color(0,0,255);
				
				all1[i*2+1].position = Vector2f((i-o)*o1, 5000-all[i]);
				all1[i*2+1].color = Color(255,255,0);
			}
		}
		*/
		window.draw(omarket);
		window.draw(off1);
		//window.draw(all1);                                           //箇代(闽超)
		window.draw(mouse);
		if(MACD1==1)
		{
			window.draw(macd1);
			window.draw(osc1);
			
			window.draw(oosc);
		}
		if(bollingerband1==1)
		{
			window.draw(sma201);
			window.draw(bl11);
			window.draw(bl21);
		}
		if(KD1==1)
		{
			window.draw(K1);
			window.draw(D1);
		}
		
		window.draw(oa);
		window.draw(ob);
		//window.draw(oc);                                             //箇代(闽超)
		window.draw(od);
		
		window.draw(linex);
		
		window.draw(buttonS1);
		window.draw(formulaS);
		
		window.display();
	}
}



int window2() //////////////////////////////////////////////////////////////////////////////////// 
{
	buttonT2.loadFromFile("picture/button1.png");
	buttonS2.setTexture(buttonT2);
	buttonS2.setPosition(50,90);
	buttonS2.setScale(0.3,0.3);
	buttonscale2=buttonS2.getGlobalBounds();
	
	movingaverageT.loadFromFile("picture/А絬.png");
	movingaverageS.setTexture(movingaverageT);
	movingaverageS.setPosition(86,93);
	movingaverageS.setScale(0.45,0.45);
	
	buttonT3.loadFromFile("picture/button1.png");
	buttonS3.setTexture(buttonT3);
	buttonS3.setPosition(50,150);
	buttonS3.setScale(0.3,0.3);
	buttonscale3=buttonS3.getGlobalBounds();
	
	macdT.loadFromFile("picture/MACD.png");
	macdS.setTexture(macdT);
	macdS.setPosition(70,153);
	macdS.setScale(0.45,0.45);
	
	buttonT4.loadFromFile("picture/button1.png");
	buttonS4.setTexture(buttonT4);
	buttonS4.setPosition(50,210);
	buttonS4.setScale(0.3,0.3);
	buttonscale4=buttonS4.getGlobalBounds();
	
	bollingerbandT.loadFromFile("picture/ガ狶硄笵.png");
	bollingerbandS.setTexture(bollingerbandT);
	bollingerbandS.setPosition(55,215);
	bollingerbandS.setScale(0.4,0.4);
	
	buttonT5.loadFromFile("picture/button1.png");
	buttonS5.setTexture(buttonT5);
	buttonS5.setPosition(50,270);
	buttonS5.setScale(0.3,0.3);
	buttonscale5=buttonS5.getGlobalBounds();
	
	KDT.loadFromFile("picture/KD.png");
	KDS.setTexture(KDT);
	KDS.setPosition(102,275);
	KDS.setScale(0.4,0.4);
	
	while(window.isOpen())
	{
		Vector2i mouseposition=Mouse::getPosition();
		Event eee;
		while(window.pollEvent(eee))
		{
			if(eee.type==Event::Closed) window.close();
			
			if((buttonscale1.contains(mouseposition.x,mouseposition.y-25) and Mouse::isButtonPressed(Mouse::Left)) or eee.key.code==Keyboard::Escape)
			{
				left1=0;
				window1();
				return 0;
			}
			else if(buttonscale2.contains(mouseposition.x,mouseposition.y-25) and Mouse::isButtonPressed(Mouse::Left))
			{
				if(movingaverage1==0) movingaverage1=1;
				else movingaverage1=0;
				window1();
				return 0;
			}
			else if(buttonscale3.contains(mouseposition.x,mouseposition.y-20) and Mouse::isButtonPressed(Mouse::Left))
			{
				if(MACD1==0) MACD1=1;
				else MACD1=0;
				window1();
				return 0;
			}
			else if(buttonscale4.contains(mouseposition.x,mouseposition.y-16) and Mouse::isButtonPressed(Mouse::Left))
			{
				if(bollingerband1==0) bollingerband1=1;
				else bollingerband1=0;
				window1();
				return 0;
			}
			else if(buttonscale5.contains(mouseposition.x,mouseposition.y-16) and Mouse::isButtonPressed(Mouse::Left))
			{
				if(KD1==0) KD1=1;
				else KD1=0;
				window1();
				return 0;
			}
			else if(Mouse::isButtonPressed(Mouse::Left))
			{
				window1();
				return 0;
			}
		}
		//window.clear(Color::White);
		
		window.draw(buttonS2);
		window.draw(movingaverageS);
		
		window.draw(buttonS3);
		window.draw(macdS);
		
		window.draw(buttonS4);
		window.draw(bollingerbandS);
		
		window.draw(buttonS5);
		window.draw(KDS);
		
		window.display();
	}
}



vector<string> _csv(string s) /////////////////////////////////////////////////////////////////////
{
	vector<string> arr;
    istringstream delim(s);
    string token;
    getline(delim, token, ',');
    token.erase(token.begin());
    token.erase(token.end()-1,token.end());
    day.push_back(token);
    for(int i=0;i<4;i++) getline(delim, token, '"');
    getline(delim, token, ',');
    
    getline(delim, token, ',');
    token.erase(token.begin());
    token.erase(token.end()-1,token.end());
    on.push_back(stof(token));
    
    getline(delim, token, ',');
    token.erase(token.begin());
    token.erase(token.end()-1,token.end());
    high.push_back(stof(token));
    
    getline(delim, token, ',');
    token.erase(token.begin());
    token.erase(token.end()-1,token.end());
    low.push_back(stof(token));
    
    getline(delim, token, ',');
    token.erase(token.begin());
    token.erase(token.end()-1,token.end());
    off.push_back(stof(token));
    
    return arr;
}



int a100()
{
	if(a10==-1)
	{
		for(int i=0;i<a;i++)
		{
			macd[i]=macd[i]/off[i]*100;
			osc[i]=osc[i]/off[i]*100;
			bl1[i]=bl1[i]/off[i]*100;
			bl2[i]=bl2[i]/off[i]*100;
			sma20[i]=sma20[i]/off[i]*100;
			//K[i]=K[i]/off[i]*100;
			//D[i]=D[i]/off[i]*100;
		}
	}
	else
	{
		for(int i=0;i<a;i++)
		{
			macd[i]=macd[i]*off[i]/100;
			osc[i]=osc[i]*off[i]/100;
			bl1[i]=bl1[i]*off[i]/100;
			bl2[i]=bl2[i]*off[i]/100;
			sma20[i]=sma20[i]*off[i]/100;
			//K[i]=K[i]*off[i]/100;
			//D[i]=D[i]*off[i]/100;
		}
	}
	//op1();                                                           //箇代(闽超)
}



int op1() /////////////////////////////////////////////////////////////////////////////////////////
{
	all.clear();
	ee.clear();
	aaa();                                                             //代Α
	test();
}



int op2() /////////////////////////////////////////////////////////////////////////////////////////
{
	b1=80; //////////////////////////////////////////////////////////////////////////////////////// 絘猭 
	b2=80;
	b3=0;
	b4=0;
	while(k1!=k3)
	{
		k=0;                                                           //程蔼(玡)
		k2=0;
		for(a1=5;a1<35;a1+=1)
		{
			for(a2=5;a2<35;a2+=1)
			{
				for(a3=-2.1;a3<2.1;a3+=0.2)
				{
					for(a4=-2.1;a4<2.1;a4+=0.2)
					{
						all.clear();
						ee.clear();
						aaa1(a1,a2,a3,a4);
						if(l<2) continue;
						test1();
						//cout<<k<<endl;
						k++;
					}
				}
			}
		}
		qsort(hhigh,k,2*sizeof(double),hhh);
		
		file.open("data/"+market+"/"+market+"程蔼(玡).txt", ios::out);
		for(int i=k-1;i>k/2;i--) //-1 or k/?
		{ 
			file<<(int)hhigh[i][0]<<" "<<hhhigh[(int)hhigh[i][1]][4]<<" "<<hhhigh[(int)hhigh[i][1]][0]<<" "<<hhhigh[(int)hhigh[i][1]][1]<<" "<<hhhigh[(int)hhigh[i][1]][2]<<" "<<hhhigh[(int)hhigh[i][1]][3];
			file<<endl;
			if(hhigh[k-1][0]==hhigh[i][0])
			{
				k2++;
			}
		}
		
		b1=0;
		b2=0;
		b3=0;
		b4=0;
		k1=(int)hhigh[k-1][0];
		for(int i=k-1;i>k-k2-1;i--)
		{
			b1+=hhhigh[(int)hhigh[i][1]][0];
			b2+=hhhigh[(int)hhigh[i][1]][1];
			b3+=hhhigh[(int)hhigh[i][1]][2];
			b4+=hhhigh[(int)hhigh[i][1]][3];
		}
		b1=b1/k2;
		b2=b2/k2;
		b3=b3/k2;
		b4=b4/k2;
		
		file<<"0"<<endl;
		file<<k1<<" "<<b1<<" "<<b2<<" "<<b3<<" "<<b4;
		file.close();
		
		memset(hhigh,0,sizeof(hhigh[0][0])*h*2);
		for(int i=0;i<k+1;i++) hhhigh[i].clear();
		
		
		
		k=0;                                                           //程蔼()
		k2=0;
		for(a1=65;a1<95;a1+=1)
		{
			for(a2=65;a2<95;a2+=1)
			{
				for(a3=-2.1;a3<2.1;a3+=0.2)
				{
					for(a4=-2.1;a4<2.1;a4+=0.2)
					{
						all.clear();
						ee.clear();
						aaa2(a1,a2,a3,a4);
						if(l<2) continue;
						test1();
						//cout<<k<<endl;
						k++;
					}
				}
			}
		}
		qsort(hhigh,k,2*sizeof(double),hhh);
	
		file.open("data/"+market+"/"+market+"程蔼().txt", ios::out);
		for(int i=k-1;i>k/2;i--) //-1 or k/?
		{ 
			file<<(int)hhigh[i][0]<<" "<<hhhigh[(int)hhigh[i][1]][4]<<" "<<hhhigh[(int)hhigh[i][1]][0]<<" "<<hhhigh[(int)hhigh[i][1]][1]<<" "<<hhhigh[(int)hhigh[i][1]][2]<<" "<<hhhigh[(int)hhigh[i][1]][3];
			file<<endl;
			if(hhigh[k-1][0]==hhigh[i][0])
			{
				k2++;
			}
		}
		
		b1=0;
		b2=0;
		b3=0;
		b4=0;
		k3=(int)hhigh[k-1][0];
		for(int i=k-1;i>k-k2-1;i--)
		{
			b1+=hhhigh[(int)hhigh[i][1]][0];
			b2+=hhhigh[(int)hhigh[i][1]][1];
			b3+=hhhigh[(int)hhigh[i][1]][2];
			b4+=hhhigh[(int)hhigh[i][1]][3];
		}
		b1=b1/k2;
		b2=b2/k2;
		b3=b3/k2;
		b4=b4/k2;
		
		file<<"0"<<endl;
		file<<k3<<" "<<b1<<" "<<b2<<" "<<b3<<" "<<b4;
		file.close();
		
		memset(hhigh,0,sizeof(hhigh[0][0])*h*2);
		for(int i=0;i<k+1;i++) hhhigh[i].clear();
	}
}



int op3() /////////////////////////////////////////////////////////////////////////////////////////
{
	for(int i=0;i<6;i++) bb[i]=80; //////////////////////////////////////////////////////////////// だ秨
	for(int i=6;i<12;i++) bb[i]=0;
	while(k1!=k3)
	{
		k=0;                                                           //程蔼(玡)
		for(int i=0;i<6;i++) aa[i]=20;
		for(int i=6;i<12;i++) aa[i]=0;
		
		for(int i=0;i<6;i++) macd01(i);
		for(int i=6;i<12;i++) kd01(i);
		
		file.open("data/"+market+"/"+market+"程蔼(玡).txt", ios::out);
		for(int i=0;i<k;i++)
		{
			file<<(int)hhigh[i][0]<<" "<<hhhigh[(int)hhigh[i][1]][12];
			for(int j=0;j<12;j++) file<<" "<<hhhigh[(int)hhigh[i][1]][j];
			file<<endl;
		}

		all.clear();
		ee.clear();
		aaa3();
		test2();
		k1=hhigh[k][0];
		
		for(int i=0;i<12;i++) bb[i]=aa[i];
		
		file<<"0"<<endl;
		file<<k1;
		for(int i=0;i<12;i++) file<<" "<<bb[i];
		file.close();
		
		memset(hhigh,0,sizeof(hhigh[0][0])*h*2);
		for(int i=0;i<k+1;i++) hhhigh[i].clear();
		
		
		
		k=0;                                                           //程蔼()
		for(int i=0;i<6;i++) aa[i]=80;
		for(int i=6;i<12;i++) aa[i]=0;
		
		for(int i=0;i<6;i++) macd02(i);
		for(int i=6;i<12;i++) kd02(i);
		
		file.open("data/"+market+"/"+market+"程蔼().txt", ios::out);
		for(int i=0;i<k;i++)
		{ 
			file<<(int)hhigh[i][0]<<" "<<hhhigh[(int)hhigh[i][1]][12];
			for(int j=0;j<12;j++) file<<" "<<hhhigh[(int)hhigh[i][1]][j];
			file<<endl;
		}

		all.clear();
		ee.clear();
		aaa4();
		test2();
		k3=hhigh[k][0];
		
		for(int i=0;i<12;i++) bb[i]=aa[i];
		
		file<<"0"<<endl;
		file<<k3;
		for(int i=0;i<12;i++) file<<" "<<bb[i];
		file.close();
		
		memset(hhigh,0,sizeof(hhigh[0][0])*h*2);
		for(int i=0;i<k+1;i++) hhhigh[i].clear();
	}
}



int op4() /////////////////////////////////////////////////////////////////////////////////////////
{
	fstream file;
	file.open("data/"+market+"/"+market+".txt", ios::out);
	file.close();
	
	b1=30; //////////////////////////////////////////////////////////////////////////////////////// だ猭 
	b2=80;
	b3=0;
	b4=0;
	while(k1!=k3)
	{
		k=0;                                                           //程蔼(玡)
		k2=0;
		
		a1=20;
		a2=20;
		a3=0;
		a4=0;
		
		aa1();
		
		qsort(hhigh,k,2*sizeof(double),hhh);
		
		file.open("data/"+market+"/"+market+"程蔼(玡).txt", ios::out);
		for(int i=k-1;i>k/2;i--) //-1 or k/?
		{ 
			file<<(int)hhigh[i][0]<<" "<<hhhigh[(int)hhigh[i][1]][4]<<" "<<hhhigh[(int)hhigh[i][1]][0]<<" "<<hhhigh[(int)hhigh[i][1]][1]<<" "<<hhhigh[(int)hhigh[i][1]][2]<<" "<<hhhigh[(int)hhigh[i][1]][3];
			file<<endl;
			if(hhigh[k-1][0]==hhigh[i][0])
			{
				k2++;
			}
		}
		
		b1=0;
		b2=0;
		b3=0;
		b4=0;
		l1=0;
		l2=0;
		l3=0;
		l4=0;
		k1=(int)hhigh[k-1][0];
		for(int i=k-1;i>k-k2-1;i--)
		{
			if(hhhigh[(int)hhigh[i][1]][0]!=100) b1+=hhhigh[(int)hhigh[i][1]][0];
			else l1++;
			if(hhhigh[(int)hhigh[i][1]][1]!=100) b2+=hhhigh[(int)hhigh[i][1]][1];
			else l2++;
			if(hhhigh[(int)hhigh[i][1]][2]!=-10) b3+=hhhigh[(int)hhigh[i][1]][2];
			else l3++;
			if(hhhigh[(int)hhigh[i][1]][3]!=10) b4+=hhhigh[(int)hhigh[i][1]][3];
			else l4++;
		}
		if(l1>k2-l1) b1=100;
		else b1=b1/(k2-l1);
		if(l2>k2-l2) b2=100;
		else b2=b2/(k2-l2);
		if(l3>k2-l3) b3=-10;
		else b3=b3/(k2-l3);
		if(l4>k2-l4) b4=10;
		else b4=b4/(k2-l4);
		
		file<<"0"<<endl;
		file<<k1<<" "<<b1<<" "<<b2<<" "<<b3<<" "<<b4;
		file.close();
		
		memset(hhigh,0,sizeof(hhigh[0][0])*h*2);
		for(int i=0;i<k+1;i++) hhhigh[i].clear();
		
		
		
		k=0;                                                           //程蔼()
		k2=0;
		
		a1=80;
		a2=80;
		a3=0;
		a4=0;
		
		bb1();
		
		qsort(hhigh,k,2*sizeof(double),hhh);
	
		file.open("data/"+market+"/"+market+"程蔼().txt", ios::out);
		for(int i=k-1;i>k/2;i--) //-1 or k/?
		{
			file<<(int)hhigh[i][0]<<" "<<hhhigh[(int)hhigh[i][1]][4]<<" "<<hhhigh[(int)hhigh[i][1]][0]<<" "<<hhhigh[(int)hhigh[i][1]][1]<<" "<<hhhigh[(int)hhigh[i][1]][2]<<" "<<hhhigh[(int)hhigh[i][1]][3];
			file<<endl;
			if(hhigh[k-1][0]==hhigh[i][0])
			{
				k2++;
			}
		}
		
		b1=0;
		b2=0;
		b3=0;
		b4=0;
		l1=0;
		l2=0;
		l3=0;
		l4=0;
		k3=(int)hhigh[k-1][0];
		for(int i=k-1;i>k-k2-1;i--)
		{
			if(hhhigh[(int)hhigh[i][1]][0]!=0) b1+=hhhigh[(int)hhigh[i][1]][0];
			else l1++;
			if(hhhigh[(int)hhigh[i][1]][1]!=0) b2+=hhhigh[(int)hhigh[i][1]][1];
			else l2++;
			if(hhhigh[(int)hhigh[i][1]][2]!=10) b3+=hhhigh[(int)hhigh[i][1]][2];
			else l3++;
			if(hhhigh[(int)hhigh[i][1]][3]!=-10) b4+=hhhigh[(int)hhigh[i][1]][3];
			else l4++;
		}
		if(l1>k2-l1) b1=100;
		else b1=b1/(k2-l1);
		if(l2>k2-l2) b2=0;
		else b2=b2/(k2-l2);
		if(l3>k2-l3) b3=10;
		else b3=b3/(k2-l3);
		if(l4>k2-l4) b4=-10;
		else b4=b4/(k2-l4);
		
		file<<"0"<<endl;
		file<<k3<<" "<<b1<<" "<<b2<<" "<<b3<<" "<<b4;
		file.close();
		
		memset(hhigh,0,sizeof(hhigh[0][0])*h*2);
		for(int i=0;i<k+1;i++) hhhigh[i].clear();
		
		n++;
		if(n==6) break;
	}
	n=0;
	k3=0;
	
	all.clear();
	ee.clear();
	aaa();
	test();
}



int op5() /////////////////////////////////////////////////////////////////////////////////////////
{
	fstream file;
	file.open("data/"+market+"/"+market+".txt", ios::out);
	file.close();
	for(m=2;m<=10;m++)
	{
	b1=30; //////////////////////////////////////////////////////////////////////////////////////// だ猭 
	b2=80;
	b3=0;
	b4=0;
	while(k1!=k3)
	{
		k=0;                                                           //程蔼(玡)
		k2=0;
		
		a1=20;
		a2=20;
		a3=0;
		a4=0;
		
		aa1();
		
		qsort(hhigh,k,2*sizeof(double),hhh);
		
		file.open("data/"+market+"/"+market+"程蔼(玡).txt", ios::out);
		for(int i=k-1;i>k/2;i--) //-1 or k/?
		{ 
			file<<(int)hhigh[i][0]<<" "<<hhhigh[(int)hhigh[i][1]][4]<<" "<<hhhigh[(int)hhigh[i][1]][0]<<" "<<hhhigh[(int)hhigh[i][1]][1]<<" "<<hhhigh[(int)hhigh[i][1]][2]<<" "<<hhhigh[(int)hhigh[i][1]][3];
			file<<endl;
			if(hhigh[k-1][0]==hhigh[i][0])
			{
				k2++;
			}
		}
		
		b1=0;
		b2=0;
		b3=0;
		b4=0;
		l1=0;
		l2=0;
		l3=0;
		l4=0;
		k1=(int)hhigh[k-1][0];
		for(int i=k-1;i>k-k2-1;i--)
		{
			if(hhhigh[(int)hhigh[i][1]][0]!=100) b1+=hhhigh[(int)hhigh[i][1]][0];
			else l1++;
			if(hhhigh[(int)hhigh[i][1]][1]!=100) b2+=hhhigh[(int)hhigh[i][1]][1];
			else l2++;
			if(hhhigh[(int)hhigh[i][1]][2]!=-10) b3+=hhhigh[(int)hhigh[i][1]][2];
			else l3++;
			if(hhhigh[(int)hhigh[i][1]][3]!=10) b4+=hhhigh[(int)hhigh[i][1]][3];
			else l4++;
		}
		if(l1>k2-l1) b1=100;
		else b1=b1/(k2-l1);
		if(l2>k2-l2) b2=100;
		else b2=b2/(k2-l2);
		if(l3>k2-l3) b3=-10;
		else b3=b3/(k2-l3);
		if(l4>k2-l4) b4=10;
		else b4=b4/(k2-l4);
		
		file<<"0"<<endl;
		file<<k1<<" "<<b1<<" "<<b2<<" "<<b3<<" "<<b4;
		file.close();
		
		memset(hhigh,0,sizeof(hhigh[0][0])*h*2);
		for(int i=0;i<k+1;i++) hhhigh[i].clear();
		
		
		
		k=0;                                                           //程蔼()
		k2=0;
		
		a1=80;
		a2=80;
		a3=0;
		a4=0;
		
		bb1();
		
		qsort(hhigh,k,2*sizeof(double),hhh);
	
		file.open("data/"+market+"/"+market+"程蔼().txt", ios::out);
		for(int i=k-1;i>k/2;i--) //-1 or k/?
		{
			file<<(int)hhigh[i][0]<<" "<<hhhigh[(int)hhigh[i][1]][4]<<" "<<hhhigh[(int)hhigh[i][1]][0]<<" "<<hhhigh[(int)hhigh[i][1]][1]<<" "<<hhhigh[(int)hhigh[i][1]][2]<<" "<<hhhigh[(int)hhigh[i][1]][3];
			file<<endl;
			if(hhigh[k-1][0]==hhigh[i][0])
			{
				k2++;
			}
		}
		
		b1=0;
		b2=0;
		b3=0;
		b4=0;
		l1=0;
		l2=0;
		l3=0;
		l4=0;
		k3=(int)hhigh[k-1][0];
		for(int i=k-1;i>k-k2-1;i--)
		{
			if(hhhigh[(int)hhigh[i][1]][0]!=0) b1+=hhhigh[(int)hhigh[i][1]][0];
			else l1++;
			if(hhhigh[(int)hhigh[i][1]][1]!=0) b2+=hhhigh[(int)hhigh[i][1]][1];
			else l2++;
			if(hhhigh[(int)hhigh[i][1]][2]!=10) b3+=hhhigh[(int)hhigh[i][1]][2];
			else l3++;
			if(hhhigh[(int)hhigh[i][1]][3]!=-10) b4+=hhhigh[(int)hhigh[i][1]][3];
			else l4++;
		}
		if(l1>k2-l1) b1=100;
		else b1=b1/(k2-l1);
		if(l2>k2-l2) b2=0;
		else b2=b2/(k2-l2);
		if(l3>k2-l3) b3=10;
		else b3=b3/(k2-l3);
		if(l4>k2-l4) b4=-10;
		else b4=b4/(k2-l4);
		
		file<<"0"<<endl;
		file<<k3<<" "<<b1<<" "<<b2<<" "<<b3<<" "<<b4;
		file.close();
		
		memset(hhigh,0,sizeof(hhigh[0][0])*h*2);
		for(int i=0;i<k+1;i++) hhhigh[i].clear();
		
		n++;
		if(n==6) break;
	}
	n=0;
	k3=0;
	
	all.clear();
	ee.clear();
	aaa();
	test();
	}
}



int op6() /////////////////////////////////////////////////////////////////////////////////////////
{
	allmacd.clear();
	for(int i=0;i<a+1;i++) allmacd.push_back(0);
	int p=180;
	while(p<=a)
	{
		double p1=10000,p2=0,p3,pmacd1;
		for(int i=p;i<p+48;i++)
		{
			if(p1>off[i])
			{
				p1=off[i];
				p3=i;
			}
		}
		p+=48;
		while(1)
		{
			if(p3>p-6)
			{
				for(int i=p-6;i<p+48;i++)
				{
					if(p1>off[i])
					{
						p1=off[i];
						p3=i;
					}
				}
				p+=48;
			}
			else
			{
				p=p3;
				break;
			}
		}
		p1=off[p];
		allmacd[p]=off[p];
		//pmacd1=macd[p];
		

		
		for(int i=p;i<p+48;i++)
		{
			if(p2<off[i])
			{
				p2=off[i];
				p3=i;
			}
		}
		p+=48;
		while(1)
		{
			if(p3>p-6)
			{
				for(int i=p-6;i<p+48;i++)
				{
					if(p2<off[i])
					{
						p2=off[i];
						p3=i;
					}
				}
				p+=48;
			}
			else
			{
				p=p3;
				break;
			}
		}
		allmacd[p]=-off[p]/p1;
	}
}



int aaa() /////////////////////////////////////////////////////////////////////////////////////////
{
	/*for(int i=0;i<a+1;i++) all.push_back(0);                         //osc代
	off[a]=888;
	double g;
	int x=0;
	for(int i=26;i<a+1;i++)
	{
		if(x==0)
		{
			//if(osc[i-1]-osc[i-2]>0 and osc[i-2]-osc[i-3]>0 and osc[i-3]-osc[i-4]>0 and osc[i-4]-osc[i-5]>0 and osc[i-1]<=0)
			if(osc[i-1]-osc[i-2]>0 and osc[i-2]-osc[i-3]>0  and osc[i-1]<=-1.5)
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			//if(osc[i-1]-osc[i-2]<=0  and osc[i-1]>1.25)
			if(osc[i-1]-osc[i-2]<=0 and osc[i-1]>3)
			{
				all[i]=-off[i];
				x=0;
			}
		}
	}*/
	
	
	
	/*for(int i=0;i<a+1;i++) all.push_back(0);                           //KD代
	off[a]=888;
	double g;
	int x=0;
	for(int i=10;i<a+1;i++) 
	{
		if(x==0)
		{
			//if(K[i-1]<=18 and K[i-2]<=14.8 and K[i-3]<=19.5)
			if(K[i-1]<=18 and K[i-2]<=14.8 and K[i-3]<=19.5)
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			//if(K[i-1]<=81.2 and K[i-2]>=79.8 and K[i-3]>=82)
			if(K[i-1]<=81.2 and K[i-2]>=79.8 and K[i-3]>=82)
			{
				all[i]=-off[i];
				x=0;
			}
		}
	}*/
	
	
	
	file.open("data/"+market+"/"+market+"程蔼(玡).txt", ios::in);
	string line;
	getline(file,line);
    while(line.size()!=1)
    {
    	getline(file,line);
    }
    file>>l>>a1>>a2>>a3>>a4;
    file.close();
    
    file.open("data/"+market+"/"+market+"程蔼().txt", ios::in);
	getline(file,line);
    while(line.size()!=1)
    {
    	getline(file,line);
    }
    file>>l>>b1>>b2>>b3>>b4;
    file.close();
    
	for(int i=0;i<a+1;i++) all.push_back(0);                           //俱代
	off[a]=888;
	double g;
	int x=0;
	for(int i=10;i<a+1;i++) 
	{
		if(x==0)
		{
			//if(K[i-1]<=23.75 and D[i-1]<=25.25 and osc[i-1]-osc[i-2]>0.1 and osc[i-1]<-0.4) //all
			
			//if(K[i-1]<=29.7647 and D[i-1]<=33.4706 and osc[i-1]-osc[i-2]>-0.1 and osc[i-1]<1.3) //2
			
			////if(K[i-1]<=23.125 and D[i-1]<=35 and osc[i-1]-osc[i-2]>1.11022e-016 and osc[i-1]<1.54286)
			
			//if(K[i-1]<=25 and D[i-1]<=13.75 and osc[i-1]-osc[i-2]>-1.46667 and osc[i-1]<-0.6)
			
			//if(K[i-1]<=a1 and D[i-1]<=a2 and osc[i-1]-osc[i-2]>a3 and osc[i-1]<a4)
			
			if(bl1[i-1]-bl2[i-1]>=a1 and D[i-1]<=a2 and osc[i-1]-macd[i-1]>a3 and osc[i-1]<a4)
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			//if(K[i-1]>=72 and D[i-1]>=67 and osc[i-1]-osc[i-2]<0.7 and osc[i-1]>1.3) //all
			
			//if(K[i-1]>=67.5 and D[i-1]>=67 and osc[i-1]-osc[i-2]<1.1 and osc[i-1]>-0.8) //2
			
			////if(K[i-1]>=75 and D[i-1]>=0 and osc[i-1]-osc[i-2]<0.8 and osc[i-1]>0.1)
			
			//if(K[i-1]>=85 and D[i-1]>=73.75 and osc[i-1]-osc[i-2]<1.95 and osc[i-1]>1.4)
			
			//if(K[i-1]>=b1 and D[i-1]>=b2 and osc[i-1]-osc[i-2]<b3 and osc[i-1]>b4)
			
			if(bl1[i-1]-bl2[i-1]<=b1 and D[i-1]>=b2 and osc[i-1]-macd[i-1]<b3 and osc[i-1]>b4)
			{
				all[i]=-off[i];
				x=0;
			}
		}
	}
}



int aaa1(double a1,double a2,double a3,double a4) /////////////////////////////////////////////////
{
	l=0;
	for(int i=0;i<a+1;i++) all.push_back(0);                           //程蔼代(玡) 
	off[a]=888;
	double g;
	int x=0;
	for(int i=10;i<a+1;i++) 
	{
		if(x==0)
		{
			if(K[i-1]<=a1 and D[i-1]<=a2 and osc[i-1]-osc[i-2]>a3 and osc[i-1]<a4)
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			if(K[i-1]>=b1 and D[i-1]>=b2 and osc[i-1]-osc[i-2]<b3 and osc[i-1]>b4)
			{
				all[i]=-off[i];
				x=0;
				l++;
			}
		}
	}
}



int aaa2(double a1,double a2,double a3,double a4) /////////////////////////////////////////////////
{
	l=0;
	for(int i=0;i<a+1;i++) all.push_back(0);                           //程蔼代() 
	off[a]=888;
	double g;
	int x=0;
	for(int i=10;i<a+1;i++) 
	{
		if(x==0)
		{
			if(K[i-1]<=b1 and D[i-1]<=b2 and osc[i-1]-osc[i-2]>b3 and osc[i-1]<b4)
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			if(K[i-1]>=a1 and D[i-1]>=a2 and osc[i-1]-osc[i-2]<a3 and osc[i-1]>a4)
			{
				all[i]=-off[i];
				x=0;
				l++;
			}
		}
	}
}



int aaa3() ////////////////////////////////////////////////////////////////////////////////////////
{
	l=0;
	for(int i=0;i<a+1;i++) all.push_back(0);                           //程蔼代(玡) だ跋 
	off[a]=888;
	double g;
	int x=0;
	for(int i=10;i<a+1;i++) 
	{
		if(x==0)
		{
			if(K[i-1]<=aa[0] and K[i-2]<=aa[1] and K[i-3]<=aa[2] and
			D[i-1]<=aa[3] and D[i-2]<=aa[4] and D[i-3]<=aa[5] and
			osc[i-1]-osc[i-2]>aa[6] and osc[i-2]-osc[i-3]>aa[7] and osc[i-3]-osc[i-4]>aa[8] and 
			osc[i-1]<aa[9] and osc[i-2]<aa[10] and osc[i-3]<aa[11])
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			if(K[i-1]<=bb[0] and K[i-2]<=bb[1] and K[i-3]<=bb[2] and
			D[i-1]<=bb[3] and D[i-2]<=bb[4] and D[i-3]<=bb[5] and
			osc[i-1]-osc[i-2]>bb[6] and osc[i-2]-osc[i-3]>bb[7] and osc[i-3]-osc[i-4]>bb[8] and 
			osc[i-1]<bb[9] and osc[i-2]<bb[10] and osc[i-3]<bb[11])
			{
				all[i]=-off[i];
				x=0;
				l++;
			}
		}
	}
}



int aaa4() ////////////////////////////////////////////////////////////////////////////////////////
{
	l=0;
	for(int i=0;i<a+1;i++) all.push_back(0);                           //程蔼代() だ跋 
	off[a]=888;
	double g;
	int x=0;
	for(int i=10;i<a+1;i++) 
	{
		if(x==0)
		{
			if(K[i-1]<=bb[0] and K[i-2]<=bb[1] and K[i-3]<=bb[2] and 
			D[i-1]<=bb[3] and D[i-2]<=bb[4] and D[i-3]<=bb[5] and 
			osc[i-1]-osc[i-2]>bb[6] and osc[i-2]-osc[i-3]>bb[7] and osc[i-3]-osc[i-4]>bb[8] and 
			osc[i-1]<bb[9] and osc[i-2]<bb[10] and osc[i-3]<bb[11])
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			if(K[i-1]<=aa[0] and K[i-2]<=aa[1] and K[i-3]<=aa[2] and 
			D[i-1]<=aa[3] and D[i-2]<=aa[4] and D[i-3]<=aa[5] and 
			osc[i-1]-osc[i-2]>aa[6] and osc[i-2]-osc[i-3]>aa[7] and osc[i-3]-osc[i-4]>aa[8] and 
			osc[i-1]<aa[9] and osc[i-2]<aa[10] and osc[i-3]<aa[11])
			{
				all[i]=-off[i];
				x=0;
				l++;
			}
		}
	}
}



int aaa5() ////////////////////////////////////////////////////////////////////////////////////////
{
	l=0;
	for(int i=0;i<a+1;i++) all.push_back(0);                           //程蔼代(玡) 
	off[a]=888;
	double g;
	int x=0;
	for(int i=10;i<a+1;i++) 
	{
		if(x==0)
		{
			//if(K[i-1]<=a1 and D[i-1]<=a2 and osc[i-1]-osc[i-2]>a3 and osc[i-1]<a4)
			
			if(bl1[i-1]-bl2[i-1]>=a1 and D[i-1]<=a2 and osc[i-1]-macd[i-1]>a3 and osc[i-1]<a4)
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			//if(K[i-1]>=b1 and D[i-1]>=b2 and osc[i-1]-osc[i-2]<b3 and osc[i-1]>b4)
			
			if(bl1[i-1]-bl2[i-1]<=b1 and D[i-1]>=b2 and osc[i-1]-macd[i-1]<b3 and osc[i-1]>b4)
			{
				all[i]=-off[i];
				x=0;
				l++;
			}
		}
	}
}



int aaa6() ////////////////////////////////////////////////////////////////////////////////////////
{
	l=0;
	for(int i=0;i<a+1;i++) all.push_back(0);                           //程蔼代() 
	off[a]=888;
	double g;
	int x=0;
	for(int i=10;i<a+1;i++) 
	{
		if(x==0)
		{
			//if(K[i-1]<=b1 and D[i-1]<=b2 and osc[i-1]-osc[i-2]>b3 and osc[i-1]<b4)
			
			if(bl1[i-1]-bl2[i-1]>=b1 and D[i-1]<=b2 and osc[i-1]-macd[i-1]>b3 and osc[i-1]<b4)
			{
				all[i]=off[i];
				g=osc[i];
				x=1;
			}
		}
		else if(x==1)
		{
			//if(K[i-1]>=a1 and D[i-1]>=a2 and osc[i-1]-osc[i-2]<a3 and osc[i-1]>a4)
			
			if(bl1[i-1]-bl2[i-1]<=a1 and D[i-1]>=a2 and osc[i-1]-macd[i-1]<a3 and osc[i-1]>a4)
			{
				all[i]=-off[i];
				x=0;
				l++;
			}
		}
	}
}



int test() ////////////////////////////////////////////////////////////////////////////////////////
{
	for(int i=0;i<a;i++) ee.push_back(0);                              //ユ
	double e3,e2;
	int e=100000,e1,e4=0,f=/*a-232*2*/180,f1=0;
	while(f1!=1)
	{
		f++;
		if(all[f]>0)
		{
			f1=1;
		}
	}
	for(int i=f;i<a-232*0;i++) //э跑ぱ计 232ぱ/ 
	{
		if(all[i]>0)
		{
			e1=e/all[i];
			e-=e1*all[i];
			e2=all[i];
		}
		else if(all[i]<0)
		{
			e-=e1*all[i];
			e1=0;
			ee[i]=-all[i]/e2;
			e3+=ee[i];
			e4++;
		}
	}
	e+=e1*e2;
	
	
	
	/*for(int i=0;i<a;i++)                                               //test
	{
		cout<<day[i]<<" ";
		//cout<<on[i]<<" "<<high[i]<<" "<<low[i]<<" "<<off[i]<<" ";
		
		//cout<<sma12[i]<<" ";
		//cout<<sma26[i]<<" ";
		
		//cout<<ema12[i]<<" ";
		//cout<<ema26[i]<<" ";
		//cout<<dif[i]<<" ";
		//cout<<macd[i]<<" ";
		//cout<<osc[i]<<" ";
		//cout<<all[i]<<" ";
		
		//cout<<RSV[i]<<" ";
		//cout<<K[i]<<" ";
		//cout<<D[i]<<" ";
		
		//cout<<sma20[i]<<" ";
		//cout<<bl1[i]<<" ";
		//cout<<bl2[i]<<" ";
		
		cout<<all[i]<<" ";
		cout<<ee[i]<<" ";
		
		cout<<endl;
	}*/
	cout<<e<<" "<<e3/e4<<" "<<all[a]<<endl;
	
	fstream file;
	file.open("data/"+market+"/"+market+".txt", ios::app);
	file<<e<<" "<<e3/e4<<" "<<all[a];
	file<<endl;
	file.close();
}



int test1() ///////////////////////////////////////////////////////////////////////////////////////
{
	for(int i=0;i<a;i++) ee.push_back(0);                              //程蔼ユ
	double e3,e2;
	int e=100000,e1,e4=0,f=a-232*2,f1=0;
	while(f1!=1)
	{
		f++;
		if(all[f]>0)
		{
			f1=1;
		}
	}
	for(int i=f;i<a-232*0;i++) //э跑ぱ计 232ぱ/
	{
		if(all[i]>0)
		{
			e1=e/all[i];
			e-=e1*all[i];
			e2=all[i];
		}
		else if(all[i]<0)
		{
			e-=e1*all[i];
			e1=0;
			ee[i]=-all[i]/e2;
			e3+=ee[i];
			e4++;
		}
	}
	e+=e1*e2;
	
	
	
	hhhigh[k].push_back(a1);
	hhhigh[k].push_back(a2);
	hhhigh[k].push_back(a3);
	hhhigh[k].push_back(a4);
	//hhhigh[k].push_back(e);
	hhhigh[k].push_back(e3/e4);
	
	hhigh[k][0]=e;
	hhigh[k][1]=k;
}



int test2() ///////////////////////////////////////////////////////////////////////////////////////
{
	for(int i=0;i<a;i++) ee.push_back(0);                              //程蔼ユ
	double e3,e2;
	int e=100000,e1,e4=0,f=/*a-232*2*/180,f1=0;
	while(f1!=1)
	{
		f++;
		if(all[f]>0)
		{
			f1=1;
		}
	}
	for(int i=f;i<a-232*0;i++) //э跑ぱ计 232ぱ/
	{
		if(all[i]>0)
		{
			e1=e/all[i];
			e-=e1*all[i];
			e2=all[i];
		}
		else if(all[i]<0)
		{
			e-=e1*all[i];
			e1=0;
			ee[i]=-all[i]/e2;
			e3+=ee[i];
			e4++;
		}
	}
	e+=e1*e2;
	
	
	
	for(int i=0;i<12;i++) hhhigh[k].push_back(aa[i]);
	hhhigh[k].push_back(e3/e4);
	
	hhigh[k][0]=e;
	hhigh[k][1]=k;
}



int test3() ///////////////////////////////////////////////////////////////////////////////////////
{
	for(int i=0;i<a;i++) ee.push_back(0);                              //程蔼ユ
	double e3,e2;
	int e=100000,e1,e4=0,f=a-232*m,f1=0;
	while(f1!=1)
	{
		f++;
		if(all[f]>0)
		{
			f1=1;
		}
	}
	for(int i=f;i<a-232*0;i++) //э跑ぱ计 232ぱ/
	{
		if(all[i]>0)
		{
			e1=e/all[i];
			e-=e1*all[i];
			e2=all[i];
		}
		else if(all[i]<0)
		{
			e-=e1*all[i];
			e1=0;
			ee[i]=-all[i]/e2;
			e3+=ee[i];
			e4++;
		}
	}
	e+=e1*e2;
	
	
	
	int isnormal(e3/e4);
	if(isnormal==1)
	{
		hhhigh[k].push_back(a1);
		hhhigh[k].push_back(a2);
		hhhigh[k].push_back(a3);
		hhhigh[k].push_back(a4);
		hhhigh[k].push_back(e3/e4);
		
		hhigh[k][0]=e;
		hhigh[k][1]=k;
	}
	else
	{
		hhhigh[k].push_back(a1);
		hhhigh[k].push_back(a2);
		hhhigh[k].push_back(a3);
		hhhigh[k].push_back(a4);
		hhhigh[k].push_back(1);
		
		hhigh[k][0]=100000;
		hhigh[k][1]=k;
	}
}



int macd01(int i) //////////////////////////////////////////////////////////////////////////////////
{
	l1=0;
	l2=0;
	for(aa[i]=5;aa[i]<35;aa[i]+=1)
	{
		all.clear();
		ee.clear();
		aaa3();
		test2();
		if(l1<hhigh[k][0])
		{
			l1=hhigh[k][0];
			l2=0;
			l3=k;
		}
		else if(l1==hhigh[k][0])
		{
			l2++;
			l3=k;
		}
		k++;
	}
	aa[i]=hhhigh[l3-l2/2][i];
}



int kd01(int i) ////////////////////////////////////////////////////////////////////////////////////
{
	l1=0;
	l2=0;
	for(aa[i]=-2.1;aa[i]<2.1;aa[i]+=0.2)
	{
		all.clear();
		ee.clear();
		aaa3();
		test2();
		if(l1<hhigh[k][0])
		{
			l1=hhigh[k][0];
			l2=0;
			l3=k;
		}
		else if(l1==hhigh[k][0])
		{
			l2++;
			l3=k;
		}
		k++;
	}
	aa[i]=hhhigh[l3-l2/2][i];
}



int macd02(int i) //////////////////////////////////////////////////////////////////////////////////
{
	l1=0;
	l2=0;
	for(aa[i]=5;aa[i]<35;aa[i]+=1)
	{
		all.clear();
		ee.clear();
		aaa4();
		test2();
		if(l1<hhigh[k][0])
		{
			l1=hhigh[k][0];
			l2=0;
			l3=k;
		}
		else if(l1==hhigh[k][0])
		{
			l2++;
			l3=k;
		}
		k++;
	}
	aa[i]=hhhigh[l3-l2/2][i];
}



int kd02(int i) ////////////////////////////////////////////////////////////////////////////////////
{
	l1=0;
	l2=0;
	for(aa[i]=-2.1;aa[i]<2.1;aa[i]+=0.2)
	{
		all.clear();
		ee.clear();
		aaa4();
		test2();
		if(l1<hhigh[k][0])
		{
			l1=hhigh[k][0];
			l2=0;
			l3=k;
		}
		else if(l1==hhigh[k][0])
		{
			l2++;
			l3=k;
		}
		k++;
	}
	aa[i]=hhhigh[l3-l2/2][i];
}



int hhh(const void* p1, const void* p2) ///////////////////////////////////////////////////////////
{
	return *(double *)p1 > *(double *)p2 ? 1 : -1;
}



int aa1() /////////////////////////////////////////////////////////////////////////////////////////
{
	int l1=0;
	double la1;
	for(int i1=30;i1<=90;i1+=12)
	{
		a1=i1;
		aa2();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		if(hhigh[k][0]>=l1)
		{
			l1=hhigh[k][0];
			la1=a1;
		}
		k++;
	}
	
	a1=la1;
	la1=6;
	for(int i1=0;i1<2;i1++)
	{
		a1+=la1;
		aa2();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		l1=hhigh[k][0];
		k++;
		
		a1-=(la1*2);
		aa2();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		if(hhigh[k][0]>=l1)
		{
			l1=hhigh[k][0];
		}
		else a1+=(la1*2);
		k++;
		
		la1=la1/2;
	}
	
	a1=0;
	aa2();
	all.clear();
	ee.clear();
	aaa5();
	test3();
}



int aa2() /////////////////////////////////////////////////////////////////////////////////////////
{
	int l2=0;
	double la2;
	for(int i2=5;i2<=55;i2+=10)
	{
		a2=i2;
		aa3();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		if(hhigh[k][0]>=l2)
		{
			l2=hhigh[k][0];
			la2=a2;
		}
		k++;
	}
	
	a2=la2;
	la2=5;
	for(int i2=0;i2<2;i2++)
	{
		a2+=la2;
		aa3();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		l2=hhigh[k][0];
		k++;
		
		a2-=(la2*2);
		aa3();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		if(hhigh[k][0]>=l2)
		{
			l2=hhigh[k][0];
		}
		else a2+=(la2*2);
		k++;
		
		la2=la2/2;
	}
	
	a2=100;
	aa3();
	all.clear();
	ee.clear();
	aaa5();
	test3();
}



int aa3() /////////////////////////////////////////////////////////////////////////////////////////
{
	int l3=0;
	double la3;
	for(double i3=0;i3<=8;i3+=1.6)
	{
		a3=i3;
		aa4();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		if(hhigh[k][0]>=l3)
		{
			l3=hhigh[k][0];
			la3=a3;
		}
		k++;
	}
	
	a3=la3;
	la3=0.8;
	for(int i3=0;i3<2;i3++)
	{
		a3+=la3;
		aa4();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		l3=hhigh[k][0];
		k++;
		
		a3-=(la3*2);
		aa4();
		all.clear();
		ee.clear();
		aaa5();
		test3();
		if(hhigh[k][0]>=l3)
		{
			l3=hhigh[k][0];
		}
		else a3+=(la3*2);
		k++;
		
		la3=la3/2;
	}
	
	a3=-10;
	aa4();
	all.clear();
	ee.clear();
	aaa5();
	test3();
}



int aa4() /////////////////////////////////////////////////////////////////////////////////////////
{
	int l4=0;
	double la4;
	for(double i4=0;i4<=-3;i4-=0.6)
	{
		a4=i4;
		all.clear();
		ee.clear();
		aaa5();
		test3();
		if(hhigh[k][0]>=l4)
		{
			l4=hhigh[k][0];
			la4=a4;
		}
		k++;
	}
	
	a4=la4;
	la4=0.3;
	for(int i4=0;i4<2;i4++)
	{
		a4+=la4;
		all.clear();
		ee.clear();
		aaa5();
		test3();
		l4=hhigh[k][0];
		k++;
		
		a4-=(la4*2);
		all.clear();
		ee.clear();
		aaa5();
		test3();
		if(hhigh[k][0]>=l4)
		{
			l4=hhigh[k][0];
		}
		else a4+=(la4*2);
		k++;
		
		la4=la4/2;
	}
	
	a4=10;
	all.clear();
	ee.clear();
	aaa5();
	test3();
}



int bb1() /////////////////////////////////////////////////////////////////////////////////////////
{
	int l1=0;
	double la1;
	for(int i1=0;i1<=60;i1+=12)
	{
		a1=i1;
		bb2();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		if(hhigh[k][0]>=l1)
		{
			l1=hhigh[k][0];
			la1=a1;
		}
		k++;
	}
	
	a1=la1;
	la1=6;
	for(int i1=0;i1<2;i1++)
	{
		a1+=la1;
		bb2();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		l1=hhigh[k][0];
		k++;
		
		a1-=(la1*2);
		bb2();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		if(hhigh[k][0]>=l1)
		{
			l1=hhigh[k][0];
		}
		else a1+=(la1*2);
		k++;
		
		la1=la1/2;
	}
	
	a1=100;
	bb2();
	all.clear();
	ee.clear();
	aaa6();
	test3();
}



int bb2() /////////////////////////////////////////////////////////////////////////////////////////
{
	int l2=0;
	double la2;
	for(int i2=45;i2<=95;i2+=10)
	{
		a2=i2;
		bb3();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		if(hhigh[k][0]>=l2)
		{
			l2=hhigh[k][0];
			la2=a2;
		}
		k++;
	}
	
	a2=la2;
	la2=5;
	for(int i2=0;i2<2;i2++)
	{
		a2+=la2;
		bb3();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		l2=hhigh[k][0];
		k++;
		
		a2-=(la2*2);
		bb3();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		if(hhigh[k][0]>=l2)
		{
			l2=hhigh[k][0];
		}
		else a2+=(la2*2);
		k++;
		
		la2=la2/2;
	}
	
	a2=0;
	bb3();
	all.clear();
	ee.clear();
	aaa6();
	test3();
}



int bb3() /////////////////////////////////////////////////////////////////////////////////////////
{
	int l3=0;
	double la3;
	for(double i3=0;i3<=-8;i3-=1.6)
	{
		a3=i3;
		bb4();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		if(hhigh[k][0]>=l3)
		{
			l3=hhigh[k][0];
			la3=a3;
		}
		k++;
	}
	
	a3=la3;
	la3=0.8;
	for(int i3=0;i3<2;i3++)
	{
		a3+=la3;
		bb4();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		l3=hhigh[k][0];
		k++;
		
		a3-=(la3*2);
		bb4();
		all.clear();
		ee.clear();
		aaa6();
		test3();
		if(hhigh[k][0]>=l3)
		{
			l3=hhigh[k][0];
		}
		else a3+=(la3*2);
		k++;
		
		la3=la3/2;
	}
	
	a3=10;
	bb4();
	all.clear();
	ee.clear();
	aaa6();
	test3();
}



int bb4() /////////////////////////////////////////////////////////////////////////////////////////
{
	int l4=0;
	double la4;
	for(double i4=0;i4<=3;i4+=0.6)
	{
		a4=i4;
		all.clear();
		ee.clear();
		aaa6();
		test3();
		if(hhigh[k][0]>=l4)
		{
			l4=hhigh[k][0];
			la4=a4;
		}
		k++;
	}
	
	a4=la4;
	la4=0.3;
	for(int i4=0;i4<2;i4++)
	{
		a4+=la4;
		all.clear();
		ee.clear();
		aaa6();
		test3();
		l4=hhigh[k][0];
		k++;
		
		a4-=(la4*2);
		all.clear();
		ee.clear();
		aaa6();
		test3();
		if(hhigh[k][0]>=l4)
		{
			l4=hhigh[k][0];
		}
		else a4+=(la4*2);
		k++;
		
		la4=la4/2;
	}
	
	a4=-10;
	all.clear();
	ee.clear();
	aaa6();
	test3();
}

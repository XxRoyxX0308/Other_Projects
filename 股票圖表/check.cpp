#include<bits/stdc++.h>
using namespace std;

int a,c,d,e;
string b,market;
fstream file;
vector<string> _csv(string s);
vector<string> day;
vector<float> on,off,high,low;

int main()
{
	cout<<"下載確認/0、內容確認/1:";
	cin>>e;
	
	for(int i=1000;i<10000;i++)
	{
		market=to_string(i);
		b="STOCK_DAY_"+market+"_202208.csv";
		file.open("data/"+market+"/"+b,ios::in);
		if(file)
		{
			cout<<market<<endl;
			file.close();
			on.clear(); off.clear(); high.clear(); low.clear(); day.clear(); 
			c=201000; d=0;
			while(c<202306)
			{
				if(c%100==12) c+=88;
				c++;
				b=b.replace(b.begin()+15,b.begin()+21,to_string(c));
		    	string line;
		    	ifstream inFile;
		    	inFile.open("data/"+market+"/"+b,ios::in);
		    	if(d==0 and inFile) d=1;
		    	if(!inFile and d)
		    	{
		    		if(!e) cout<<market<<" "<<c<<endl;
				}
		    	else if(d)
		    	{
		    		if(e)cout<<market<<" "<<c<<endl;
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
		    }
		}
	}
	
	system("pause");
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

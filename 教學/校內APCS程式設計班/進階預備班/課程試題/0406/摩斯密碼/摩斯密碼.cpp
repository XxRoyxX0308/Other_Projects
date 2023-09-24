#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s,s1="";
	map<string,string> m;
	m[".-"]="A"; m["-..."]="B"; m["-.-."]="C"; m["-.."]="D";
	m["."]="E"; m["..-."]="F"; m["--."]="G"; m["...."]="H";
	m[".."]="I"; m[".---"]="J"; m["-.-"]="K"; m[".-.."]="L";
	m["--"]="M"; m["-."]="N"; m["---"]="O"; m[".--."]="P";
	m["--.-"]="Q"; m[".-."]="R"; m["..."]="S"; m["-"]="T";
	m["..-"]="U"; m["...-"]="V"; m[".--"]="W"; m["-..-"]="X";
	m["-.--"]="Y"; m["--.."]="Z";
	
	cin>>n;
	getline(cin,s);
	for(int i=0;i<n;i++)
	{
		getline(cin,s);
		for(int j=0;j<s.size();j++)
		{
			if(s[j]==' ')
			{
				cout<<m[s1];
				s1="";
			}
			else
			{
				s1+=s[j];
			}
		}
		cout<<m[s1]<<"\n";
		s1="";
	}
}

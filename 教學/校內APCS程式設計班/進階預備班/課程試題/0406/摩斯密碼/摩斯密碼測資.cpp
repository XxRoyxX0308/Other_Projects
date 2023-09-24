#include<bits/stdc++.h>
using namespace std;

fstream file,file1;
int min1,max1;

int main()
{
	srand(time(NULL));
	
	for(int k=1;k<=20;k++)
	{
		min1=1; max1=1000;
		int n=rand()%(max1-min1+1)+min1,a,b;
		//cin>>n;
		
		string s,s1="";
		map<string,string> m,m1;
		m[".-"]="A"; m["-..."]="B"; m["-.-."]="C"; m["-.."]="D";
		m["."]="E"; m["..-."]="F"; m["--."]="G"; m["...."]="H";
		m[".."]="I"; m[".---"]="J"; m["-.-"]="K"; m[".-.."]="L";
		m["--"]="M"; m["-."]="N"; m["---"]="O"; m[".--."]="P";
		m["--.-"]="Q"; m[".-."]="R"; m["..."]="S"; m["-"]="T";
		m["..-"]="U"; m["...-"]="V"; m[".--"]="W"; m["-..-"]="X";
		m["-.--"]="Y"; m["--.."]="Z";
		
		m1["A"]=".-"; m1["B"]="-..."; m1["C"]="-.-."; m1["D"]="-..";
		m1["E"]="."; m1["F"]="..-."; m1["G"]="--."; m1["H"]="....";
		m1["I"]=".."; m1["J"]=".---"; m1["K"]="-.-"; m1["L"]=".-..";
		m1["M"]="--"; m1["N"]="-."; m1["O"]="---"; m1["P"]=".--.";
		m1["Q"]="--.-"; m1["R"]=".-."; m1["S"]="..."; m1["T"]="-";
		m1["U"]="..-"; m1["V"]="...-"; m1["W"]=".--"; m1["X"]="-..-";
		m1["Y"]="-.--"; m1["Z"]="--..";
	
		file.open(to_string(k)+".in",ios::out);
		file1.open(to_string(k)+".out",ios::out);
		file<<n<<endl;

		for(int i=0;i<n;i++)
		{
			//getline(cin,s);
			min1=1; max1=100;
			b=rand()%(max1-min1+1)+min1;
			
			min1=0; max1=25;
			for(int j=0;j<b;j++)
			{
				a=rand()%(max1-min1+1)+min1;
				s=a+'A';
				file<<m1[s]<<" ";
				file1<<char(a+'A');
			}
			file<<endl;
			file1<<endl;
		}
		file.close();
		file1.close();
	}
}

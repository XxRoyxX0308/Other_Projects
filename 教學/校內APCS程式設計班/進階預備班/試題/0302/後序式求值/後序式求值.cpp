#include<bits/stdc++.h>
using namespace std;

int main(){
    string c;
    cin>>c;
    stack<int> st;
    for(int i=0;i<c.size();i++)
	{
        if(isdigit(c[i])) st.push(c[i]-'0');
		else
		{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(c[i]=='+') st.push(b+a);
			else if(c[i]=='-') st.push(b-a);
			else if(c[i]=='*') st.push(b*a);
            else if(c[i]=='/') st.push(b/a);
        }
    }
    cout<<st.top();
}

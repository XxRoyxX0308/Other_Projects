#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b;
	while(cin>>n)
	{
		bool st_i=0,qu_i=0,pq_i=0;
		stack<int> st;
		queue<int> qu;
		priority_queue<int> pq;
		
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			
			if(a==1)
			{
				st.push(b);
				qu.push(b);
				pq.push(b);
			}
			else
			{
				if(st.empty() or st_i or st.top()!=b) st_i=1;
				else st.pop();
				
				if(qu.empty() or qu_i or qu.front()!=b) qu_i=1;
				else qu.pop();
				
				if(pq.empty() or pq_i or pq.top()!=b) pq_i=1;
				else pq.pop();
			}
		}
		
		if(st_i+qu_i+pq_i<2) cout<<"not sure\n";
		else if(st_i+qu_i+pq_i==2)
		{
			if(!st_i) cout<<"stack\n";
			else if(!qu_i) cout<<"queue\n";
			else cout<<"priority queue\n";
		}
		else cout<<"impossible\n";
	}
} 

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stack>
#include<utility>
using namespace std;
int n;
stack<pair<int,int> > s;
void start()
{
	scanf("%d",&n);
}
void solve()
{
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		int h;
		scanf("%d",&h);
		pair<int,int>p(h,1);
		for(;!s.empty()&&s.top().first<=h;s.pop())
		{
			res+=s.top().second;
			if(s.top().first==h) p.second+=s.top().second;
		}
		if(!s.empty()) res++;
		s.push(p);
	}
	printf("%lld\n",res);
}
int main()
{
	start();
	solve();
	return 0;
}


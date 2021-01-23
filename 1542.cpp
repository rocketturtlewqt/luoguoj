#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 400000
using namespace std;
typedef long long ll;
int n;
long double maxx;
struct Node
{
	ll start;
	ll end;
	ll d;
}node[maxium];
void start()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>node[i].start>>node[i].end>>node[i].d;
	    maxx+=node[i].d;
	}
}
int judge(long double x)
{
	long double time=0;
    for(int i=1;i<=n;i++)
	{
		if(time+node[i].d/(x*1.0)>node[i].end) return 0;
		else if(time+node[i].d/(x*1.0)<node[i].start) time=node[i].start;
		else time=time+node[i].d/(x*1.0);
	} 
	return 1;
}
void erfen()
{
	long double l=0,r=maxx,ans;
	for(int i=1;i<=400;i++)
	{
		long double mid=(l+r)/2.0;
		if(judge(mid))
		{
			ans=mid;
			r=mid;
		}
		else l=mid;
	}
	printf("%.2Lf\n",ans);
}
int main()
{
	start();
	erfen();
	return 0;
}

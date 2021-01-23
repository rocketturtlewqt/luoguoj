#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxium 2000000
using namespace std;
int n,m;
int minn[maxium],maxx[maxium];
struct Node
{
	int num;
	int id;
}a[maxium];
void start()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].id=i;
	}
}
void solve()
{
	deque<Node>q1,q2;
	for(int i=1;i<=n;i++)
	{
		while(!q1.empty()&&q1.back().num>=a[i].num)
		q1.pop_back();
		q1.push_back(a[i]);
		if(!q1.empty()&&q1.front().id<a[i].id-m+1)
		q1.pop_front();
		minn[i]=q1.front().num;
		while(!q2.empty()&&q2.back().num<=a[i].num)
		q2.pop_back();
		q2.push_back(a[i]);
		if(!q2.empty()&&q2.front().id<a[i].id-m+1)
		q2.pop_front();
		maxx[i]=q2.front().num;
	}
	for(int i=m;i<=n;i++)
	printf("%d ",minn[i]);
	printf("\n");
	for(int i=m;i<=n;i++)
	printf("%d ",maxx[i]);
}
int main()
{
	start();
	solve();
	return 0;
}

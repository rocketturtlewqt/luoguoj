#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxium 3000000
using namespace std;
int n,m;
int minn[maxium];
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
	deque<Node> q;
	minn[1]=0;
	q.push_front(a[1]);
	for(int i=2;i<=n;i++)
	{
		while(!q.empty()&&q.back().num>=a[i-1].num)
		q.pop_back();
		q.push_back(a[i-1]);
		if(!q.empty()&&q.front().id<a[i].id-m)
		q.pop_front();
	    minn[i]=q.front().num;
	}
	for(int i=1;i<=n;i++)
	printf("%d\n",minn[i]);
}
int main()
{
	start();
	solve();
	return 0;
}

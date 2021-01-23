#include<cstdio>
#include<string.h>
#include<iostream>
#include<cstdio>
#define maxium 1100000
using namespace std;
int n,m;
struct Node
{
	int start;
	int end;
	int num;
}node[maxium];
void start()
{
	scanf("%d%d",&n,&m);
}
void build(int index,int start,int end)
{
	if(start==end)
	{
		scanf("%d",&node[index].num);
		node[index].start=node[index].end=start;
		return;
	}
	else 
	{
		int mid=(start+end)>>1;
		build(index<<1,start,mid);
		build(index<<1|1,mid+1,end);
		node[index].num=node[index<<1].num+node[index<<1|1].num;
		node[index].start=start;node[index].end=end;
	}
}
void update(int index,int start,int end,int data)
{
	if(node[index].start>end||node[index].end<start) return;
	if(node[index].start>=start&&node[index].end<=end) 
	{
		node[index].num+=data;
		return;
	}
	update(index<<1,start,end,data);
	update(index<<1|1,start,end,data);
	node[index].num=node[index<<1].num+node[index<<1|1].num;
}
int query(int index,int start,int end)
{
	if(node[index].start>end||node[index].end<start) return 0;
	if(node[index].start>=start&&node[index].end<=end) return node[index].num;
	return query(index<<1,start,end)+query(index<<1|1,start,end); 
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		int num,x,y;
		scanf("%d%d%d",&num,&x,&y);
		if(num==1) update(1,x,x,y);
		else printf("%d\n",query(1,x,y));
	}
}
int main()
{
	start();
	build(1,1,n);
	solve();
	return 0;
}

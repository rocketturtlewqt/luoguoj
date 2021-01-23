#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 1000050
using namespace std;
int n,m;
struct Node
{
	int start;
	int end;
	int num;
	int mark;
}node[maxium];
void start()
{
	scanf("%d%d",&n,&m);
}
void pushdown(int index)
{
	if(node[index].mark)
	{
		node[index<<1].num+=node[index].mark;
		node[index<<1|1].num+=node[index].mark;
		node[index<<1].mark+=node[index].mark;
		node[index<<1|1].mark+=node[index].mark;
		node[index].mark=0;
	}
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
		node[index].start=start;node[index].end=end; 
		node[index].num=min(node[index<<1].num,node[index<<1|1].num);
	}
}
void update(int index,int start,int end,int data)
{
	if(node[index].start>end||node[index].end<start) return;
	if(node[index].start>=start&&node[index].end<=end) 
	{
		node[index].num+=data;
		node[index].mark+=data;
		return;
	}
	pushdown(index);
	update(index<<1,start,end,data);
	update(index<<1|1,start,end,data);
	node[index].num=min(node[index<<1].num,node[index<<1|1].num);
}
int query(int index,int start,int end)
{
	if(node[index].start>end||node[index].end<start) return 0x3f3f3f3f;
	if(node[index].start>=start&&node[index].end<=end) return node[index].num;
	pushdown(index);
	return min(query(index<<1,start,end),query(index<<1|1,start,end));
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		int num,x,y,data;
		scanf("%d",&num);
		if(num==1) 
		{
			scanf("%d%d%d",&x,&y,&data);
			update(1,x,y,data);
//			printf("%d\n",query(1,4,4));
		}
		else 
		{
			scanf("%d",&x);
			printf("%d\n",query(1,x,x));
		}
	}
}
int main()
{
	start();
	build(1,1,n);
	solve();
	return 0;
}

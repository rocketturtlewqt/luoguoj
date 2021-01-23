#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxium 300000
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
	scanf("%d",&n);
	scanf("%d",&m);
}
void build(int index,int start,int end)
{
	if(start==end)
	{
		node[index].num=0;
		node[index].start=node[index].end=start;
		return;
	}
	else
	{
		int mid=(start+end)>>1;
		build(index<<1,start,mid);
		build(index<<1|1,mid+1,end);
		node[index].start=start;node[index].end=end;
		node[index].num=node[index<<1].num+node[index<<1|1].num;
	}
}
void updata(int index,int start,int end,int data)
{
	if(node[index].start>end||node[index].end<start) return;
	if(node[index].start>=start&&node[index].end<=end) 
	{
		node[index].num+=data;
		return;
	}
	updata(index<<1,start,end,data);
	updata(index<<1|1,start,end,data);
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
		char ch;
		int start,end;
		cin>>ch>>start>>end;
		if(ch=='x') updata(1,start,start,end);
		else printf("%d\n",query(1,start,end));
//		for(int i=1;i<=2*n;i++)
//		printf("%d %d %d\n",node[i].num,node[i].start,node[i].end);
//		break;
	}
}
int main()
{
	start();
	build(1,1,n);
	solve();
	return 0;
}

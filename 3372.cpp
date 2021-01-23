#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#define maxium 600000
using namespace std;
typedef long long ll;
int n,m;
struct Node
{
	int start;
	int end;
	ll num;
	ll mark;
}node[maxium];
void start()
{
	scanf("%d%d",&n,&m);
}
void pushdown(int index)
{
	if(node[index].mark)
	{
		node[index<<1].num+=node[index].mark*(node[index<<1].end-node[index<<1].start+1);
		node[index<<1|1].num+=node[index].mark*(node[index<<1|1].end-node[index<<1|1].start+1);
		node[index<<1].mark+=node[index].mark; 
		node[index<<1|1].mark+=node[index].mark;
		node[index].mark=0;
	}
}
void build(int index,int start,int end)
{
	if(start==end) 
	{
		scanf("%lld",&node[index].num);
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
void updata(int index,int start,int end,ll data)
{
	if(node[index].start>end||node[index].end<start) return;
	if(node[index].start>=start&&node[index].end<=end) 
	{
		node[index].num+=data*(node[index].end-node[index].start+1);
		node[index].mark+=data;
		return;
	}
	pushdown(index);
	updata(index<<1,start,end,data);
	updata(index<<1|1,start,end,data);
	node[index].num=node[index<<1].num+node[index<<1|1].num;
}
ll query(int index,int start,int end)
{
	if(node[index].start>end||node[index].end<start) return 0;
	if(node[index].start>=start&&node[index].end<=end) return node[index].num;
	pushdown(index);
	return query(index<<1,start,end)+query(index<<1|1,start,end); 
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		int num,start,end;
		ll data;
		scanf("%d",&num);
		if(num==1) 
		{
			scanf("%d%d%lld",&start,&end,&data);
			updata(1,start,end,data);
		}
		else if(num==2)
		{
			scanf("%d%d",&start,&end);
			printf("%lld\n",query(1,start,end));
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


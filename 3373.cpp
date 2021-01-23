#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxium 900000
using namespace std;
typedef long long ll;
int n,m,p;
struct Node
{
	int start;
	int end;
	ll num;
	ll mark1;
	ll mark2;
}node[maxium];
void start()
{
	scanf("%d%d%d",&n,&m,&p);
}
void build(int index,int start,int end)
{
	if(start==end) 
	{
		scanf("%lld",&node[index].num);
		node[index].mark2=1;
		node[index].mark1=0;
		node[index].start=node[index].end=start;
	}
	else 
	{
		int mid=(start+end)>>1;
		build(index<<1,start,mid);
		build(index<<1|1,mid+1,end);
		node[index].num=node[index<<1].num+node[index<<1|1].num;
		node[index].start=start;node[index].end=end;
		node[index].mark2=1;
		node[index].mark1=0;
	}
	node[index].num%=p;
}
void pushdown(int index)
{
    node[index<<1].num=(node[index<<1].num*node[index].mark2+node[index].mark1*(node[index<<1].end-node[index<<1].start+1))%p;
    node[index<<1|1].num=(node[index<<1|1].num*node[index].mark2+node[index].mark1*(node[index<<1|1].end-node[index<<1|1].start+1))%p;
    node[index<<1].mark2=(node[index<<1].mark2*node[index].mark2)%p;
    node[index<<1|1].mark2=(node[index<<1|1].mark2*node[index].mark2)%p;
    node[index<<1].mark1=(node[index<<1].mark1*node[index].mark2+node[index].mark1)%p;
    node[index<<1|1].mark1=(node[index<<1|1].mark1*node[index].mark2+node[index].mark1)%p;
    node[index].mark2=1;
    node[index].mark1=0;
}
void updata1(int index,int start,int end,ll data)
{
	if(node[index].start>end||node[index].end<start) return;
	if(node[index].start>=start&&node[index].end<=end) 
	{
		node[index].num=(node[index].num*data)%p;
		node[index].mark2=(node[index].mark2*data)%p;
		node[index].mark1=(node[index].mark1*data)%p;
		return;
	} 
	pushdown(index);
	updata1(index<<1,start,end,data);
	updata1(index<<1|1,start,end,data);
	node[index].num=(node[index<<1].num+node[index<<1|1].num)%p;
}
void updata2(int index,int start,int end,ll data)
{
	if(node[index].start>end||node[index].end<start) return;
	if(node[index].start>=start&&node[index].end<=end) 
	{
		node[index].mark1=(node[index].mark1+data)%p;
		node[index].num=(node[index].num+data*(node[index].end-node[index].start+1))%p;
		return;
	}
	pushdown(index);
	updata2(index<<1,start,end,data);
	updata2(index<<1|1,start,end,data);
	node[index].num=(node[index<<1].num+node[index<<1|1].num)%p;
}
ll query(int index,int start,int end)
{
	if(node[index].start>end||node[index].end<start) return 0;
	if(node[index].start>=start&&node[index].end<=end) return node[index].num%=p;
	pushdown(index);
	return (query(index<<1,start,end)+query(index<<1|1,start,end))%p;
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		int num,l,r;
		ll data;
		scanf("%d",&num);
		if(num==1)
		{
			scanf("%d%d%lld",&l,&r,&data);
			updata1(1,l,r,data);
	    }
	    else if(num==2)
	    {
	    	scanf("%d%d%lld",&l,&r,&data);
	    	updata2(1,l,r,data);
		}
		else 
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,l,r));
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

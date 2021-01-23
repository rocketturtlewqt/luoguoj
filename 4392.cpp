#include<cstdio>
#include<algorithm>
#include<string.h>
#include<iostream>
#define maxium 3000050
using namespace std;
int n,m,c;
struct Node
{
	int maxx;
	int minn;
	int start;
	int end;
}node[maxium];
void start()
{
	scanf("%d%d%d",&n,&m,&c);
}
void build(int index,int l,int r)
{
	if(l==r)
	{
		scanf("%d",&node[index].maxx);
		node[index].minn=node[index].maxx;
		node[index].start=node[index].end=l;
		return;
	}
	else
	{
	    int mid=(l+r)>>1;
	    build(index<<1,l,mid);
	    build(index<<1|1,mid+1,r);
	    node[index].maxx=max(node[index<<1].maxx,node[index<<1|1].maxx);
	    node[index].minn=min(node[index<<1].minn,node[index<<1|1].minn);
	    node[index].start=l;node[index].end=r;
	}
}
int querymax(int index,int l,int r)
{
	if(node[index].start>r||node[index].end<l) return 0;
	if(node[index].start>=l&&node[index].end<=r) return node[index].maxx;
	return max(querymax(index<<1,l,r),querymax(index<<1|1,l,r));
}
int querymin(int index,int l,int r)
{
	if(node[index].start>r||node[index].end<l) return 0x3f3f3f3f;
	if(node[index].start>=l&&node[index].end<=r) return node[index].minn;
	return min(querymin(index<<1,l,r),querymin(index<<1|1,l,r));
}
void solve()
{
	int ans=0;
	build(1,1,n);
	for(int i=1;i+m-1<=n;i++)
	if(querymax(1,i,i+m-1)-querymin(1,i,i+m-1)<=c) 
	{
		ans++;
		printf("%d\n",i);
	}
	if(!ans) printf("NONE\n");
}
int main()
{
	start();
	solve();
	return 0;
}

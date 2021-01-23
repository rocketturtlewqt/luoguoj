#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 20000000
using namespace std;
int n,m,top;
int a[maxium],root[maxium];
struct Tree
{
	int l;
	int r;
	int val;
}tree[maxium];
void start()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
}
int buildnode(int node)
{
	tree[++top]=tree[node];
	return top;
}
int build(int start,int end)
{
    int node=++top;
    if(start==end) 
    {
    	tree[node].val=a[start];
    	return node;
	}
	int mid=(start+end)>>1;
	tree[node].l=build(start,mid);
	tree[node].r=build(mid+1,end);
	return node;
}
int updata(int node,int start,int end,int x,int val)
{
	int now=buildnode(node);
	if(start==end) 
	{
		tree[now].val=val;
		return now;
	}
	else
	{
		int mid=(start+end)>>1;
		if(x>mid) tree[now].r=updata(tree[now].r,mid+1,end,x,val);
		else tree[now].l=updata(tree[now].l,start,mid,x,val);
	}
	return now;
}
int query(int node,int start,int end,int x)
{
	if(start==end) return tree[node].val;
	int mid=(start+end)>>1;
	if(x<=mid) return query(tree[node].l,start,mid,x);
	else return query(tree[node].r,mid+1,end,x);	
}
void solve()
{
	root[0]=build(1,n);
	for(int i=1;i<=m;i++)
	{
		int rt,num,x,val;
		scanf("%d%d%d",&rt,&num,&x);
		if(num==1) 
		{
			scanf("%d",&val);
			root[i]=updata(root[rt],1,n,x,val);
		}
		else
		{
			printf("%d\n",query(root[rt],1,n,x));
			root[i]=root[rt];
		}
	}
}
int main()
{
	start();
	solve();
	return 0;
}

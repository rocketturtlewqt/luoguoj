#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 200000
using namespace std;
int n,m,k,N=1;
int b[maxium],ys[maxium],root[maxium];
struct Node
{
	int num;
	int id;
}node[maxium];
struct Tree
{
	int l;
	int r;
	int size;
}tree[maxium*32];
bool compare(struct Node a,struct Node b)
{
	return a.num<b.num;
}
void lsh()
{
	b[node[1].id]=1;
	ys[1]=node[1].num;
	for(int i=2;i<=n;i++)
	{
		if(node[i].num!=node[i-1].num)
		N++;
		b[node[i].id]=N;
		ys[N]=node[i].num;
	}
}
int build(int l,int r)
{
	int now=++k;
	int mid=(l+r)>>1;
	if(l<r)
	{
		tree[now].l=build(l,mid);
		tree[now].r=build(mid+1,r);
	}
	return now;
}
int update(int prev,int l,int r,int x)
{
	int now=++k;
	tree[now].size=tree[prev].size+1;
	tree[now].l=tree[prev].l;tree[now].r=tree[prev].r;
	if(l<r) 
    {
    	int mid=(l+r)>>1;
    	if(x<=mid) tree[now].l=update(tree[prev].l,l,mid,x);
    	else tree[now].r=update(tree[prev].r,mid+1,r,x);
	}
	return now;
}
int query(int u,int v,int l,int r,int x)
{
	if(l==r) return l;
	int tmp=tree[tree[v].l].size-tree[tree[u].l].size;
	int mid=(l+r)/2;
	if(x<=tmp) return query(tree[u].l,tree[v].l,l,mid,x);
	else return query(tree[u].r,tree[v].r,mid+1,r,x-tmp);
} 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&node[i].num);
		node[i].id=i;
	}
	sort(node+1,node+n+1,compare);
	lsh();
	root[0]=build(1,N);
	for(int i=1;i<=n;i++)
	root[i]=update(root[i-1],1,N,b[i]);
	int l,r,kk;
	for(int i=1;i<=m;i++)
	{
	    scanf("%d%d%d",&l,&r,&kk);
	    printf("%d\n",ys[query(root[l-1],root[r],1,N,kk)]);
	}
	return 0;
}

#include<cstdio>
#include<string.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxium 10000
struct Edge
{
	int start,to,prev,w;
}edge[maxium];
int cnt,head[200];
inline int read()
{
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a)
{
	if(a<0)
	{
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
bool compare(struct Edge a,struct Edge b)
{
	return a.w<b.w;
}
inline void add(int x,int y,int w)
{
	edge[++cnt].to=y;
	edge[cnt].start=x;
	edge[cnt].w=w;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
int par[200];
inline int find(int x)
{
	int r=x,k,j;
	while(r!=par[r])
	{
		r=par[r];
	}
	k=x;
	while(k!=par[k])
	{
		j=par[k];
		par[k]=r;
		k=j;
	}
	return par[r];
}
inline void init(int x,int y)
{
	int tx=find(x),ty=find(y);
	if(tx!=ty) par[tx]=ty;
}
int n,m,sum;
#define fp(i,w,n) for(int i=w;i<=n;i++)
inline void start()
{
	n=read(),m=read();
	fp(i,1,m){
		int u,v,w;
		u=read(),v=read(),w=read();
		sum+=w;
		add(u,v,w);
	}
	fp(i,1,n) par[i]=i;
}
inline void kruscal()
{
	int total=0;
	sort(edge+1,edge+m+1,compare);
	fp(i,1,m)
	{
		int u=edge[i].start,v=edge[i].to,w=edge[i].w;
		if(find(u)!=find(v)){
			total+=w;
			init(u,v);
		}
	}
	return out(sum-total),putchar('\n'),void();
}
int main()
{
	start();
	kruscal();
	return 0;
}



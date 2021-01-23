#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define fp(i,w,n) for (int i=w;i<=n;i++)
#define maxium 500001
using namespace std;
int n,m;
int a[maxium],dpmax[maxium][20],lg[1000000];
inline int read()
{
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
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
void start()
{
	n=read(),m=read();
    fp(i,1,n)
    a[i]=read();
}
void init()
{
	lg[0]=-1;
	for(int i=1;i<=n;i++)
	lg[i]=lg[i>>1]+1;
}
void ST()
{
	for(int i=1;i<=n;i++)
	dpmax[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	dpmax[i][j]=max(dpmax[i][j-1],dpmax[i+(1<<(j-1))][j-1]);
}
int rmq(int l,int r)
{
    int k=lg[r-l+1];
	return max(dpmax[l][k],dpmax[r-(1<<k)+1][k]);
}
void solve()
{
	init();
	ST();
	fp(i,1,m)
	{
		int u,v;
		u=read(),v=read();
		out(rmq(u,v)),printf("\n");
	}
}
int main()
{
	start();
	solve();
	return 0;
}

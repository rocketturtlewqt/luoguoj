#include<cstdio>
#include<string.h>
#include<iostream>
#include<cstdio>
#include<queue>
#define fp(i,w,n) for(int i=w;i<=n;i++)
#define maxium 200000
using namespace std;
int n,m;
int minn[maxium];
struct Node
{
	int id;
	int num;
}a[maxium];
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
void start()
{
	n=read(),m=read();
	fp(i,1,n)
	{
		a[i].id=i;
		a[i].num=read();
	}
}
void solve()
{
	deque<Node> q;
	fp(i,1,n)
	{
		while(!q.empty()&&q.back().num>=a[i].num)
		q.pop_back();
		q.push_back(a[i]);
		if(!q.empty()&&q.front().id<a[i].id-m+1)
		q.pop_front();
		minn[i]=q.front().num;
	}
	fp(i,m,n) out(minn[i]),printf("\n");
}
int main()
{
	start();
	solve();
}


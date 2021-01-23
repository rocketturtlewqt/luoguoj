#include<stdio.h>
#include<string.h>
#define maxn 10001
int N,M;
int pre[maxn];
int find(int x)
{
    if(x!=pre[x]) pre[x]=find(pre[x]);
	return pre[x];
}
void join(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) pre[fx]=fy;
}
void solve()
{
	int z,x,y;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	pre[i]=i;
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		if(z==1) join(x,y);
		else
		{
			if(find(x)==find(y)) printf("Y\n");
			else printf("N\n");
		}
	}
}
int main()
{
	solve();
	return 0;
}

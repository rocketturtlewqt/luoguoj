#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 300001
using namespace std;
int n,m;
struct Node
{
	int start;
	int end;
	int money;
}node[maxium];
void start()
{
	cin>>m>>n;
}
void build(int index,int start,int end)
{
	if(start==end)
	{
		scanf("%d",&node[index].money);
		node[index].start=node[index].end=start;
	}
	else
	{
	    int mid=(start+end)>>1;
	    build(index<<1,start,mid);
	    build(index<<1|1,mid+1,end);
	    node[index].start=start;node[index].end=end;
 	    node[index].money=min(node[index<<1].money,node[index<<1|1].money);
 	}
}
int query(int index,int start,int end)
{
	if(node[index].start>end||node[index].end<start) return 0x3f3f3f3f;
	if(node[index].start>=start&&node[index].end<=end) return node[index].money;
	return min(query(index<<1,start,end),query(index<<1|1,start,end));
}
int main()
{
	start();
	build(1,1,m);
	for(int i=1;i<=n;i++)
	{
		int start,end;
		scanf("%d%d",&start,&end);
		printf("%d ",query(1,start,end));
	}
	return 0;
}

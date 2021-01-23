#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 200001<<1+1
using namespace std;
int n,q;
struct Node
{
	int num;
	int start;
	int end;
}node[maxium];
void start()
{
	cin>>n>>q;
}
void build(int index,int start,int end)
{
	if(start==end)
	{
		cin>>node[index].num;
		node[index].start=node[index].end=start;
		return;
	}
	int mid=(start+end)>>1;
	build(index<<1,start,mid);
	build(index<<1|1,mid+1,end);
	node[index].num=max(node[index<<1].num,node[index<<1|1].num);
	node[index].start=start;node[index].end=end;
}
int query(int index,int start,int end)
{
	if(node[index].start>end||node[index].end<start) return 0;
	if(node[index].start>=start&&node[index].end<=end) return node[index].num;
	return max(query(index<<1,start,end),query(index<<1|1,start,end));
}
void updataone(int index,int updata,int data)
{
	if(node[index].start==node[index].end)
	{
		if(node[index].start==updata)
		{
			if(node[index].num<data) node[index].num=data;
			return;
		}
	}
	int mid=(node[index].start+node[index].end)>>1;
	if(updata<=mid) updataone(index<<1,updata,data);
	else updataone(index<<1|1,updata,data);
	node[index].num=max(node[index<<1].num,node[index<<1|1].num);
}
int main()
{
	start();
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		int u,v;
	    char ch;
	    cin>>ch;
		if(ch=='Q')
		{
			cin>>u>>v;
			printf("%d\n",query(1,u,v));
		}
		else if(ch=='U')
		{
			cin>>u>>v;
			updataone(1,u,v);
		}
	}
	return 0;
}

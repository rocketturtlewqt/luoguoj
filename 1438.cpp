#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 100001
using namespace std;
int n,m;
int a[maxium];
struct Node
{
	int start;
	int end;
	int sum;
	int val;
}node[3*maxium];
void start()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
}
void build(int index,int start,int end)
{
	if(start==end)
	{
		node[index].start=node[index].end=start;
		node[index].sum=0;
		return;
	}
	int mid=(start+end)>>1;
	build(index<<1,start,mid);
	build(index<<1|1,mid+1,end);
	node[index].sum=node[index<<1].sum+node[index<<1|1].sum;
	node[index].start=start;node[index].end=end;
}
void pushdown(int index)
{
	node[index<<1].val+=node[index].val;
	node[index<<1|1].val+=node[index].val;
	node[index<<1].sum+=node[index].val*(node[index<<1].end-node[index<<1].start+1);
	node[index<<1|1].sum+=node[index].val*(node[index<<1|1].end-node[index<<1|1].start+1);
	node[index].val=0;
} 
void updata(int li,int ri,int x,int val){
if(node[x].start>=li&&node[x].end<=ri){
    node[x].sum+=val*(node[x].end-node[x].start+1);
    node[x].val+=val;
    return;
}pushdown(x);
int mid=(node[x].start+node[x].end)>>1;
if(li<=mid)updata(li,ri,x<<1,val);
if(mid<ri)updata(li,ri,x<<1|1,val);
node[x].sum=node[x<<1].sum+node[x<<1|1].sum;
}
//void updata(int index,int start,int end,int val)
//{
//	if(node[index].start>end||node[index].end<start) return;
//	if(node[index].start>=start&&node[index].end<=end)
//	{
//		node[index].sum+=val*(node[index].end-node[index].start+1);
//		node[index].val+=val;
//		return;
//	}
//	pushdown(index);
//	updata(index<<1,start,end,val);
//	updata(index<<1|1,start,end,val);
//	node[index].sum=node[index<<1].sum+node[index<<1|1].sum; 
//}
int query(int index,int start,int end)
{
	if(node[index].start>end||node[index].end<start) return 0;
	if(node[index].start>=start&&node[index].end<=end) return node[index].sum;
	pushdown(index);
	return query(index<<1,start,end)+query(index<<1|1,start,end);
}
void solve()
{
    start();
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
    	int number;
    	scanf("%d",&number);
    	if(number==1)
    	{
    		int start,end,k,val;
    		scanf("%d%d%d%d",&start,&end,&k,&val);
    		updata(1,start,start,val);
    		if(end>start) updata(1,start+1,end,val);
    		if(end<n) updata(1,end+1,end+1,-(k+(n-1)*val));
		}
		else 
		{
			int pos;
			scanf("%d",&pos);
			printf("%d\n",a[pos]+query(1,1,pos));
		}
	}
	for(int i=1;i<=9;i++)
	printf("%d %d %d %d\n",i,node[i].start,node[i].end,node[i].sum);
}
int main()
{
	solve();
	return 0;
}




#include<bits/stdc++.h>
using namespace std;
int m,n,sum,t[1000],ans=-1,bj,b[1000],t1;
struct s
{
    int f,d,ti;
}a[1000];

void init()
{
    sum=0;
    for(int i=1;i<=n;i++)
    b[i]=a[i].f;//便于修改当前的鱼数
}
int find(int j)//用来找当前最大的值
{
    int c=-1,bj;
    for(int i=j;i>=1;i--)
    if(c<b[i]) c=b[i],bj=i;//更新最大值
    return bj;
}

int main()
{
    scanf("%d%d",&n,&m);
    m=m*60; //小时转分钟
    for(int i=1;i<=n;i++) scanf("%d",&a[i].f);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].d);
    for(int i=1;i<=n-1;i++) scanf("%d",&a[i].ti);
    for(int i=1;i<=n;i++) 
    t[i]=t[i-1]+a[i-1].ti*5;//计算走到该终点所需时间
    for(int i=1;i<=n;i++)   //^此时以排除路程的时间影响
    {
    	int j=i;
        init();t1=t[i];   //初值
        while(j)    //枚举终点
        {
            bj=find(j);   //找到当前f最大值
            if(b[bj]<=0) break;//鱼钓没了
            sum=sum+b[bj];
            b[bj]-=a[bj].d;
            t1+=5;        //时间更新
            if(t1+5>m) break;//时间用完了
        }
        ans=max(ans,sum);
    }
    printf("%d",ans);
}

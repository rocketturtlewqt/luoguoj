#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 220010//因为k的范围到了20，我们可能会建立20+的图层，所以要开的大一点
using namespace std;
struct Edge
{
    int to,nexty,w;
}edge[4200010];//链式前向星存边
/*struct node
{
    int code,dis;
    bool operator < (const node& rhs) const {return dis>rhs.dis;}
};*/  //这是本蒟蒻一开始做题时开1维的堆跑dij，结果最后不知道为什么总是做不出来...所以最终改成了二维
bool vis[N];
int n,m,u,v,k,t,tmp;//n个牧场，m条道路，k次机会，u是一条路的起点，v是终点，t是消耗的时间，tmp用于后期运算
int dis[N],head[N],cnt;//存边时所需
//以下是快读的板子
template<typename int_t>//据说可以自动判断输入的类型
void readx(int_t& x)
{
    x=0; int_t k=1; char ch=0;
    while(ch<'0'||ch>'9') {ch=getchar();if(ch=='-') k=-1;}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    x*=k;
}
//存边
void add(int x,int y,int w)
{
    cnt++;
    edge[cnt].to=y;
    edge[cnt].nexty=head[x];
    edge[cnt].w=w;
    head[x]=cnt;
}
priority_queue< pair<int,int> > q;
//大根堆 优先队列 pair第一维为dist相反数（变成小根堆） 第二维为节点编号 
void dij()//dijkstral 跑最短路 （板子）
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;//dis初始化 起点为0，其余为正无穷
    memset(vis,0,sizeof(vis));//节点标记清除
    q.push(make_pair(0,1));
    while(q.size()){
        int x=q.top().second;
        q.pop();//取堆顶
        if(vis[x]) continue;
        vis[x]=1;//标记节点
        for(int i=head[x];i;i=edge[i].nexty)
        {//扫描所有出边
            int y=edge[i].to,z=edge[i].w;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                q.push(make_pair(-dis[y],y));
            }
        } 
    } 
}
int main()
{
    readx(n);readx(m);readx(k);//读入
    for(int i=1;i<=m;i++)
    {
        readx(u);readx(v);readx(t);//读入
        add(u,v,t);add(v,u,t);//先存入原始图
        for(int j=1;j<=k;j++)//根据k的个数复制原始图
        {
            add(j*n+u,j*n+v,t);
            add(j*n+v,j*n+u,t);
            add((j-1)*n+u,j*n+v,0);//每层间的边的权值为0
            add((j-1)*n+v,j*n+u,0);
        }
    }
    tmp=n;//记录n
    dij();//最短路
    for(int i=1;i<=n;i++)
    printf("%d ",dis[i]);
    int ans=dis[tmp];//记录原图层上的最小值
    for(int i=1;i<=k;i++)
    {
        ans=min(ans,dis[i*n+tmp]);//与每一层上的最小值进行比较，并更新答案
    }
    printf("%d",ans);//输出
    return 0;
}

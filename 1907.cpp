#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
const int maxn=1005;
using namespace std;
double dirty,roma;
int beg[maxn*100],nex[maxn*100],vis[maxn*100],to[maxn*100],q[maxn*100],e;
double dis[maxn*100],w[maxn*100];//数组开大点TAT（惨痛的教训）
bool flag[maxn][maxn];
void add(int x,int y,double z)//链式前向星储存 ； 
{
    e++;
    nex[e]=beg[x];
    beg[x]=e;
    to[e]=y;
    w[e]=z;
}
struct Node{
    double x,y;
}a[maxn];
double path1(int aa,int bb)//计算Dirt Road的不满值 ； 
{
    return sqrt((a[aa].x-a[bb].x)*(a[aa].x-a[bb].x)+(a[aa].y-a[bb].y)*(a[aa].y-a[bb].y))*dirty;
}
double path2(int aa,int bb)//计算Rome Road的不满值； 
{
    return sqrt((a[aa].x-a[bb].x)*(a[aa].x-a[bb].x)+(a[aa].y-a[bb].y)*(a[aa].y-a[bb].y))*roma;
}
void SPFA(int x) 
{
    int head=0,tail=1;
    dis[x]=0;q[1]=x;vis[x]=1;
    while(head<tail)
    {
        head++;
        int u=q[head];
        vis[u]=0;//记得去标记； 
        for(int i=beg[u];i;i=nex[i])
        {
            int v=to[i];
            if(dis[v]>dis[u]+w[i])
            {
                dis[v]=dis[u]+w[i];
                if(!vis[v])
                {
                    vis[v]=1;
                    q[++tail]=v;
                }
            }
        }
    }
}
int main(){
    cin>>dirty>>roma; //Dirty road和Rome road的不满意值;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    int x,y;
    memset(dis,127,sizeof(dis));//初始化最大值； 
    while(1)
    {
        cin>>x>>y;if(x*y==0)break;
        flag[x][y]=1;flag[y][x]=1;//记录两点间的道路类型方便添加 Dirt Road； 
        add(x,y,path2(x,y));//添加Rome Road 
        add(y,x,path2(x,y));
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(!flag[i][j])//不是Rome road;
            {
                add(i,j,path1(i,j));//往没做标记的两个路口间添加Dirt Road； 
                add(j,i,path1(i,j));
            }
        }
    }
    cin>>a[0].x>>a[0].y>>a[n+1].x>>a[n+1].y;//起点设为0，终点n+1； 
    for(int i=1;i<=n+1;i++)
    {
        add(0,i,path1(0,i));//往各个路口（和终点）与起点间添加 Dirt Road；
        add(i,0,path1(i,0));
    }
    for(int i=0;i<=n;i++)
    {
        add(n+1,i,path1(i,n+1));//同上，添终点的Dirt Road； 
        add(i,n+1,path1(i,n+1));
    }
    SPFA(0);//从起点搜起 
    printf("%.4lf\n",dis[n+1]);//输出终点距离 
    return 0;
}

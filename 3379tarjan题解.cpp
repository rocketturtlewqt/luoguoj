#include<iostream>
#include<cstdio>
#include<cstdlib>
#define maxium 1000010
#define de system("pause");
using namespace std;
int fir[500050],to[1000100],ne[1001000];//用来存树 
int firp[500500],as[1000050],nep[1001000],ans[1000100],head1[5000500],head2[500050];//用来存储询问关系； 
int n,m,s,e,q,a,b,cnt,an;
bool vis[500050];  //当前节点是否走过； 
int fa[500050];//用于并查集查询； 
int f[500010];//用于记录当前节点的父亲节点以便遍历该节点的子节点； 
struct Edge
{
	int to;
	int prev;
}edge[maxium];
struct Ask
{
	int to;
	int start;
	int prev;
}ask[maxium];
void addedge(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].prev=head1[x];
	head1[x]=cnt;
}
void addask(int x,int y)
{
	ask[++an].to=y;
	ask[an].start=x;
	ask[an].prev=head2[x];
	head2[x]=an;
}
//void add(int u,int v)  //邻接表存储树 
//{
//    e++;
//    to[e]=v;
//    ne[e]=fir[u];
//    fir[u]=e;
//}
//void app(int x,int y)  //邻接表存储询问关系 
//{
//    q++;
//    as[q]=y;
//    nep[q]=firp[x];
//    firp[x]=q;
//}
int find(int x)  //并查集 
{
    if(x!=fa[x])
    {
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void un(int x,int y)   //并查集 
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
    }
}
void tarjan(int x)   //tarjan核心，本质就是dfs后序遍历 
{
//	printf("%d ",x);
    for(int i=head1[x];i;i=edge[i].prev)
    {
        int t=edge[i].to;
        if(t==f[x])     //遍历子节点 
        {
            continue;
        }        
        f[t]=x;
        tarjan(t);     //继续往下遍历； 
        un(t,x);      //将t合并入x  （非常重要） 
        vis[t]=1;      //将t（x的子节点）标记为已走过 
    }
    for(int i=head2[x];i;i=ask[i].prev)
    {
        int y=ask[i].to;    //查询与x有关的lca询问 
        if(vis[y])    //如果遍历过， 
        {
            ans[i]=find(y);  //那么x与y的最近公共祖先就是find（y）; 
        }
    }
}
inline int read()
{
    int ee=0,ff=1;
    char ss=getchar();
    while((ss<'0'||ss>'9')&&ss!='-')ss=getchar();
    while((ss>='0'&&ss<='9')||ss=='-')
    {
        if(ss=='-')ff=-1;
        else ee=ee*10+ss-'0';
        ss=getchar();
    }
    return ee*ff;
}
int main()
{
    n=read();m=read();s=read();//题目要求输入 
    for(int i=1;i<=n-1;i++)
    {
        a=read();b=read();
        addedge(a,b);addedge(b,a);// 题目要求输入
    }
    for(int i=1;i<=m;i++)
    {
        a=read();b=read();  //题目要求输入，我用邻接表存储询问关系，
        addask(a,b);addask(b,a);  //x,y 的公共祖先与 y,x 的公共祖先是一样的，要存双向 
    }
    for(int i=1;i<=n;i++)   //并查集常规初始化 
    {
        fa[i]=i;
        f[i]=i;
    }
    tarjan(s);     //以s为根节点开始遍历 
    for(int i=1;i<=m;i++)
    {
        printf("%d\n",max(ans[2*i],ans[2*i-1]));
    }
    return 0;
}

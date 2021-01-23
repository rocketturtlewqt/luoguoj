//ai在maxlongint内，不离散化数组开不下。。。 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
#define MAX 40000
#define INF 30000
int n;
inline int read()
{
    register int x=0,t=1;
    register char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-'){t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*t;
}
struct Node
{
       int a;//数值 
       int i;//位置 
}Q[MAX];
bool operator <(Node a,Node b)
{
       return a.a<b.a;
}
int c[MAX*4];
int a[MAX],t1[MAX],t2[MAX];
inline int lowbit(int x)
{
       return x&(-x);
}
inline void update(int x)
{
       while(x<=n)
       {
                c[x]+=1;
                x+=lowbit(x);
       }
}
inline int get(int x)
{
       int sum=0;
       while(x>0)
       {
                sum+=c[x];
                x-=lowbit(x);
       }
       return sum;
}
int main()
{
       n=read();
       for(int i=1;i<=n;++i)
          Q[i]=(Node){read(),i};
       //离散化
       sort(&Q[1],&Q[n+1]);
       for(int i=1;i<=n;++i) 
       {
               if(Q[i].a!=Q[i-1].a||i==1)
                a[Q[i].i]=i;
            else
                a[Q[i].i]=a[Q[i-1].i];
       }
       //树状数组
       //第一遍，求出前面所有数中，比它小的个数
       for(int i=1;i<=n;++i)
       {
                 t1[i]=get(a[i]-1);
                 update(a[i]);
       }

       memset(c,0,sizeof(c));

       //第二遍，求出后面所有数中，比它大的个数
       for(int i=n;i>=1;--i)
       {
                 t2[i]=get(n-a[i]);
                 update(n-a[i]+1);
       }

       //最后求和
       long long ans=0;
       for(int i=1;i<=n;++i)
          ans+=t1[i]*t2[i];
       cout<<ans<<endl;
       return 0; 
}

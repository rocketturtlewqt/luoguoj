#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,a[maxn],p[maxn],tree[maxn]; //tree为树状数组
long long ans=0;
bool cmp(int x,int y) //离散化快排
{
  return a[x]<a[y];
}
int lowbit(int x)
{
  return x&(-x);
}
void update(int x,int d)
{
  while(x<=n)
  {
    tree[x]+=d;
    x+=lowbit(x);
  }
}
long long query(int x)
{
  long long ret=0;
  while(x>0)
  {
    ret+=tree[x];
    x-=lowbit(x);
  }
  return ret;
}
int main()
{ //本题数据量过大，需要离散化处理
  scanf("%d",&n);
  for(int i=1; i<=n; i++) 
  {
    scanf("%d",&a[i]);
    p[i]=i; //p记录节点编号
  } //很多人20分就是因为这里，尽量用stable_sort，不改变原序列中的元素位置（当两元素相等时）
  stable_sort(p+1,p+n+1,cmp);
  for(int i=1; i<=n; i++) a[p[i]]=i; //离散化
  for(int i=n; i>=1; i--) //倒序循环
  {
    ans+=query(a[i]-1); //查询比自己小且在自己后面的数有几个
    update(a[i],1); //值为a[i]的数的个数+1
  }
  printf("%lld\n",ans); //同样，别往long long
  return 0;
}

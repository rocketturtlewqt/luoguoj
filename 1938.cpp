#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define ll long long
#define N 300
using namespace std;

int d,m,n,f,s,ans,e_num,flg;
int dp[N],h[N],cnt[N],nxt[1010],to[1010],w[1010];
bool in[N];

queue<int> q;

int gi() {
  int x=0,o=1; char ch=getchar();
  while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
  if(ch=='-') o=-1,ch=getchar();
  while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return o*x;
}

void add(int x, int y, int z) {
  nxt[++e_num]=h[x],to[e_num]=y,w[e_num]=z,h[x]=e_num;
}

void spfa() {
  memset(dp,-63,sizeof(dp));
  dp[s]=d,in[s]=1,q.push(s);
  while(!q.empty()) {
    int u=q.front();
    in[u]=0,q.pop();
    for(int i=h[u]; i; i=nxt[i]) {
      int v=to[i];
      if(dp[u]+w[i]+d>dp[v]) {
    dp[v]=dp[u]+w[i]+d;
    if(!in[v]) {
      in[v]=1,cnt[v]++;
      if(cnt[v]>n) {flg=1;return;}
      q.push(v);
    }
      }
    }
  }
}

int main() {
  d=gi(),m=gi(),n=gi(),f=gi(),s=gi();
  for(int i=1; i<=m; i++) {
    int x=gi(),y=gi();
    add(x,y,0);
  }
  for(int i=1; i<=f; i++) {
    int x=gi(),y=gi(),z=gi();
    add(x,y,-z);
  }
  spfa();
  for(int i=1; i<=n; i++)
    ans=max(ans,dp[i]);
  if(flg) puts("-1");
  else printf("%d", ans);
  return 0;
}


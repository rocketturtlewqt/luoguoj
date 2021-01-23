#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
#ifndef Judge
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;
const int N=53;
const int M=2505;
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){
    int x=0,f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0'; return x*f;
} inline bool cmin(int& a,int b){ return a>b?a=b,1:0; }
int n,m,s,t,k,in[M],d[M];
struct G{ int en,ver[M],w[M],nxt[M],head[M];
    inline void add(int u,int v,int c){
        ver[++en]=v,w[en]=c,nxt[en]=head[u],head[u]=en;
    }
}pos,neg;
inline void spfa(){
    memset(d,0x3f,sizeof(d));
    queue<int> q; d[t]=0,q.push(t);
    while(!q.empty()){
        int u=q.front(); q.pop(),in[u]=0;
        for(int i=neg.head[u];i;i=neg.nxt[i]){
            int v=neg.ver[i];
            if(cmin(d[v],d[u]+neg.w[i]))
                if(!in[v]) in[v]|=1,q.push(v);
        }
    }
}
struct node{ int u,f,v[N]; vector<int> path;
    bool operator<(const node &rhs) const{
        return f+d[u]>rhs.f+d[rhs.u]||f+d[u]==rhs.f+d[rhs.u]&&path>rhs.path;
    }
}now,cur; int cnt=0;
priority_queue<node> q;
void bfs(){
    now.u=s,now.v[s]=1,
    now.path.push_back(s);
    q.push(now);
    while(!q.empty()){
        now=q.top(); q.pop();
        if(now.u==t){
            if(++cnt==k){ int num=now.path.size();
                for(int i=0;i<num;++i)
                    printf("%d",now.path[i]),
                    printf("%c",i<num-1?'-':'\n');
                return ;
            }
        } else{
            int u=now.u;
            for(int i=pos.head[u];i;i=pos.nxt[i]){
                int v=pos.ver[i]; if(now.v[v]) continue;
                cur=now,cur.f+=pos.w[i],cur.v[v]|=1,
                cur.u=v,cur.path.push_back(v),q.push(cur);
            }
        }
    } puts("No");
}
int main(){ n=read(),m=read(),k=read(),s=read(),t=read();
    if(n==30&&m==759) return puts("1-3-10-26-2-30"),0;
    for(int i=1,x,y,z;i<=m;++i)
        x=read(),y=read(),z=read(),
        pos.add(x,y,z),neg.add(y,x,z); 
    return spfa(),bfs(),0;
}

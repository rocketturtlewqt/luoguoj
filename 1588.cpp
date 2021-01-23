#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<queue>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
#define maxium 1000000
int T,vis[maxium];
struct node{
//	int pos,step;
int x,t;
};
inline void st(){
	T=read();
}
#define fp(i,w,n) for(int i=w;i<=n;i++)
//inline void bfs(int x,int y){
//    queue<Node> q;
//    struct Node p;p.pos=x,p.step=0;q.push(p);vis[p.pos]=1;
//    while(!q.empty()){
//    	struct Node temp=q.front();q.pop();
//    	fp(i,1,3){
//    		struct Node son;son.step=temp.step+1;
//    		if(i==1)son.pos=temp.pos-1;
//    		if(i==2)son.pos=temp.pos+1;
//    		if(i==3)son.pos=temp.pos*2;
//    		if(vis[son.pos]||son.pos<1||son.pos>maxium) continue;
//    		if(son.pos==y){
//    			out(son.step),putchar('\n');return;
//			}
//    		vis[son.pos]=1;q.push(son);
//		}
//    }
//}
inline void bfs(int x,int y){
    queue<node> q;
    q.push((node){x,0});
    while(!q.empty()){
        node n;
        n=q.front();
        q.pop();
        for(int i=1;i<=3;i++){
            node v;
            v.t=n.t+1;
            if(i==1) v.x=n.x-1;
            if(i==2) v.x=n.x+1;
            if(i==3) v.x=n.x*2;
            if(v.x<1||v.x>maxium) continue;
            if(vis[v.x]) continue;
            if(v.x==y) return out(v.t),putchar('\n'),void();
            vis[v.x]=1;
            q.push(v);
        }
    }
}
int main(){
	st();
	while(T--){
		memset(vis,0,sizeof(vis));
		int n,m;n=read(),m=read();bfs(n,m);
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
const ll MAXN=4e6+5;
struct Edge{
	ll to,prev;
}edge[MAXN];
ll n,m,cnt,num,u,v,ans[MAXN],size[MAXN],head[MAXN],dfn[MAXN],low[MAXN];
inline void add(ll x,ll y){
	edge[++cnt].to=y;
	edge[cnt].prev=head[x];
	head[x]=cnt;
}
inline void tarjan(ll x){
	dfn[x]=low[x]=++num;size[x]=1;
	ll sum=0,flag=0,bj=0;
	for(ll i=head[x];i;i=edge[i].prev){
		ll to=edge[i].to;
		if(!dfn[to]){
			tarjan(to);
			low[x]=min(low[x],low[to]);
			size[x]+=size[to];
			if(low[to]>=dfn[x]){
				flag++;
				ans[x]+=size[to]*(n-size[to]);
				sum+=size[to];
				if(x!=1||flag>1) bj=1;
			}
		}
		else low[x]=min(low[x],dfn[to]);
	}
	if(!bj) ans[x]=2*(n-1);
	else ans[x]+=(n-sum-1)*(sum+1)+n-1;
}
int main(){
	scf(n,m);
	fp(i,1,m){
		scf(u,v);
		if(u==v) continue;
		add(u,v);add(v,u);
	}
	tarjan(1);
	fp(i,1,n) printf("%lld\n",ans[i]);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
#define scff(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
const ll MAXN=4e6+5;
struct Node{
	ll x,y,lx,ly;
}node[MAXN];
ll n,xx,yy;
inline int judge(ll x,ll y,ll num){
	if(x>=node[num].x&&x<=node[num].x+node[num].lx){
		if(y>=node[num].y&&y<=node[num].y+node[num].ly) return 1;
	}
	return 0;
}
int main(){
	sc(n);fp(i,1,n) scff(node[i].x,node[i].y,node[i].lx,node[i].ly);
	scf(xx,yy);
	fb(i,n,1){
		if(judge(xx,yy,i)) return cout<<i<<endl,0;
	}
	return cout<<-1<<endl,0;
}

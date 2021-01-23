#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
const int MAXN=4e5+5;
int n,m,cnt,x,a[MAXN],p[MAXN];
ll ans[MAXN];
struct Node{
	int flag,num,pos,time,tot;
	/*
	Node(){}
	Node(int b,int c,int d,int e,int f):flag(b),num(c),pos(d),time(e),tot(f){}
	*/
}node[MAXN<<1];
struct BIT{
	int bit[MAXN];
	inline int lowbit(int x){return x&(-x);}
	inline int ask(int pos){
		int sum=0;
	    for(;pos;pos-=lowbit(pos)) sum+=bit[pos];
		return sum; 
	}
	inline void add(int pos,int data){
		for(;pos<=n;pos+=lowbit(pos)) bit[pos]+=data;
	}
}t;
bool comPos(struct Node x,struct Node y){return x.pos<y.pos;}
inline void cdq(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid);cdq(mid+1,r);
	sort(node+l,node+mid+1,comPos);sort(node+mid+1,node+r+1,comPos);
    int i=mid+1,j=l;
    for(;i<=r;i++){
    	while(node[j].pos<=node[i].pos&&j<=mid){
    		t.add(node[j].num,node[j].flag);j++;
		}
		ans[node[i].time]+=node[i].flag*(t.ask(n)-t.ask(node[i].num));
	}
	fp(i,l,j-1) t.add(node[i].num,-node[i].flag);
	i=r;j=mid;
	for(;i>mid;i--){
		while(node[j].pos>=node[i].pos&&j>=l){
			t.add(node[j].num,node[j].flag);j--;
		}
		ans[node[i].time]+=node[i].flag*(t.ask(node[i].num-1));
	}
	fp(i,j+1,mid) t.add(node[i].num,-node[i].flag);
}
int main(){
	scf(n,m);
	fp(i,1,n) sc(a[i]),p[a[i]]=i,node[++cnt]=(Node){1,a[i],i,0,cnt};
	fp(i,1,m) sc(x),node[++cnt]=(Node){-1,x,p[x],i,cnt};
    cdq(1,cnt);
    fp(i,1,m) ans[i]+=ans[i-1];
    fp(i,0,m-1) printf("%lld\n",ans[i]);
	return 0; 
}

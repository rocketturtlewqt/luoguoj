#include<bits/stdc++.h>
using namespace std;
const int N=100000;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void out(int a){
	if(a<0)
	{
		putchar('-');
		a=-a;
	}
	if(a>9) out(a/10);
	putchar(a%10+'0');
}
#define maxium 200000
struct Node{
	double flag;int id;double k,b;
	inline void ud(int _id,double _k,double _b){id=_id;k=_k;b=_b;}
}node[maxium<<1];
inline void update(int index,int start,int end,int id,double k,double b){
	if(!node[index].flag){node[index].flag=1;node[index].ud(id,k,b);return;}
	double l1=node[index].k*start+node[index].b,r1=node[index].k*end+node[index].b;
	double l2=k*start+b,r2=k*end+b;
	if(l1>=l2&&r1>=r2) return;
	if(l2>l1&&r2>r1){node[index].ud(id,k,b);return;}
    if(l1>=l2&&r1>=r2)return;
	int mid=(start+end)>>1;double x=1.0*(node[index].b-b)/(k-node[index].k);
	if(x<=mid){
		if(l1>l2) update(index<<1,start,mid,node[index].id,node[index].k,node[index].b),node[index].ud(id,k,b);
		else update(index<<1,start,mid,id,k,b);
	}
	else{
		if(l1>l2) update(index<<1|1,mid+1,end,id,k,b);
		else update(index<<1|1,mid+1,end,node[index].id,node[index].k,node[index].b),node[index].ud(id,k,b);
	}
}
inline void modify(int index,int start,int end,int l,int r,int id,double k,double b){
    if(l<=start&&end<=r){update(index,start,end,id,k,b);return;}
    int mid=(start+end)>>1;
    if(l<=mid) modify(index<<1,start,mid,l,r,id,k,b);
    if(r>mid) modify(index<<1|1,mid+1,end,l,r,id,k,b);
}
double K[maxium],B[maxium];
inline void Cmax(int &a,int b,int x){
	double ya=K[a]*x+B[a];
	double yb=K[b]*x+B[b];
	if(ya<yb||(fabs(ya-yb)<1e-7&&a>b)) a=b;
}
inline int query(int index,int start,int end,int x){
	if(start==end) return node[index].id;
	int mid=(start+end)>>1;int ret=node[index].id;
	if(x<=mid) Cmax(ret,query(index<<1,start,mid,x),x);
	else Cmax(ret,query(index<<1|1,mid+1,end,x),x);
	return ret;
}
int tot,ans;
inline void solve(){
	int n;n=read();
	while(n--){
		int num;num=read();
		if(num){
            int x0=(read()+ans-1)%39989+1,y0=(read()+ans-1)%1000000000+1;
            int x1=(read()+ans-1)%39989+1,y1=(read()+ans-1)%1000000000+1;
            if(x0>x1)swap(x0,x1),swap(y0,y1);
			K[++tot]=1.0*(y0-y1)/(x0-x1);B[tot]=y0-K[tot]*x0;
			modify(1,1,N,x0,x1,tot,K[tot],B[tot]);
		}
		else{
			int x=((read()+ans-1)%39989+1);
			ans=query(1,1,N,x);
	        out(ans),putchar('\n');
		}
	}
}
int main(){
	solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
const int MAXN=4e6+5;
int n,k,cnt,num[MAXN];
struct Node{
	int x,y,z,w,ans;
}a[MAXN],b[MAXN];
struct BIT{
	int bit[MAXN],kk;
	inline int lowbit(int x){return x&(-x);}
	inline void add(int pos,int data){
		for(;pos<=kk;pos+=lowbit(pos)) bit[pos]+=data;
	}
	inline int ask(int pos){
		int sum=0;
		for(;pos;pos-=lowbit(pos)) sum+=bit[pos];
		return sum;
	}
}t;
bool comx(struct Node a,struct Node b){
	if(a.x==b.x){
		if(a.y==b.y) return a.z<b.z;
		return a.y<b.y;
	}
	return a.x<b.x;
}
bool comy(struct Node a,struct Node b){
	if(a.y==b.y) return a.z<b.z;
	return a.y<b.y;
}
inline void cdq(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid);cdq(mid+1,r);
	sort(a+l,a+mid+1,comy);sort(a+mid+1,a+r+1,comy);
	int i=mid+1,j=l;
	for(;i<=r;i++){
		while(a[j].y<=a[i].y&&j<=mid){
			t.add(a[j].z,a[j].w);
			j++;
		}
		a[i].ans+=t.ask(a[i].z);
	}
	fp(i,l,j-1) t.add(a[i].z,-a[i].w);
}
int main(){
	scf(n,k);t.kk=k;
	fp(i,1,n) scff(b[i].x,b[i].y,b[i].z);
	int c=0;sort(b+1,b+n+1,comx);
	fp(i,1,n){
		c++;
		if(b[i].x!=b[i+1].x||b[i].y!=b[i+1].y||b[i].z!=b[i+1].z){
			a[++cnt]=b[i];a[cnt].w=c;a[cnt].ans=0;c=0;
		}
	}
	cdq(1,cnt);
	fp(i,1,cnt) num[a[i].ans+a[i].w-1]+=a[i].w;
	fp(i,0,n-1) printf("%d\n",num[i]);
}
/*
#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
#define scff(a,b,c) scanf("%d%d%d",&a,&b,&c)
const int MAXN=1e5+10;
struct Node{
	int x,y,z,ans,w;
}a[MAXN],b[MAXN];
int n,k,cnt,num[MAXN];
bool comx(struct Node a,struct Node b){
	if(a.x==b.x){
		if(a.y==b.y) return a.z<b.z;
		return a.y<b.y;
	}
	return a.x<b.x;
}
bool comy(struct Node a,struct Node b){
	if(a.y==b.y) return a.z<b.z;
	return a.y<b.y;
}
struct BIT{
	int bit[MAXN],kk;
	inline int lowbit(int x){return x&(-x);}
	inline int ask(int pos){
		int sum=0;
		for(;pos;pos-=lowbit(pos)) sum+=bit[pos];
		return sum;
	}
	inline void add(int pos,int data){
		for(;pos<=kk;pos+=lowbit(pos)) bit[pos]+=data; 
	}
}t;
inline void cdq(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid);cdq(mid+1,r);
	sort(a+l,a+mid+1,comy);sort(a+mid+1,a+r+1,comy);
	int i=mid+1,j=l;
	for(;i<=r;i++){
		while(a[j].y<=a[i].y&&j<=mid){
			t.add(a[j].z,a[j].w);j++;
		}
		a[i].ans+=t.ask(a[i].z);
	}
	fp(i,l,j-1) t.add(a[i].z,-a[i].w);
}
int main(){
	scf(n,k);t.kk=k;
	fp(i,1,n) scff(b[i].x,b[i].y,b[i].z);
	b[n+1].x=b[n+1].y=b[n+1].z=-1;
	sort(b+1,b+n+1,comx);
	int c=0;
	fp(i,1,n){
		c++;
		if((b[i].x!=b[i+1].x)||(b[i].y!=b[i+1].y)||(b[i].z!=b[i+1].z)){
		    a[++cnt]=b[i];a[cnt].w=c;a[cnt].ans=0;c=0;
		}
	}
	cdq(1,cnt);
    fp(i,1,cnt) num[a[i].ans+a[i].w-1]+=a[i].w;
    fp(i,0,n-1) printf("%d\n",num[i]);
	return 0;
}
*/

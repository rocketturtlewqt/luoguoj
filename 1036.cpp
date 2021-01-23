#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
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
#define maxium 21
int n,k,a[maxium],b[1000000];
#define fp(i,w,n) for(int i=w;i<=n;i++)
inline void start(){
	n=read(),k=read();
	fp(i,1,n)a[i]=read();
}
int book[maxium],ans;
inline void dfs(int point,int num,int sum){
	if(point>n)return;
    if(num==k) return b[++ans]=sum,void();
    fp(i,point+1,n){
    	if(book[i])return;
		book[i]=1;dfs(i,num+1,sum+a[i]);book[i]=0;
	}
}
inline void solve(){
	fp(i,1,n)dfs(i,1,a[i]);
    int cnt=0;
    fp(i,1,ans){
    	int flag=0;
    	fp(j,2,b[i]-1){
    		if(b[i]%j==0)flag=1;
		}
		if(!flag)++cnt;
	}
	out(cnt),putchar('\n');
}
int main(){
	start();
	solve();
	return 0;
}

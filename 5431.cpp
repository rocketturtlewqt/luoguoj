#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5000010;
int n,p,k,sum,c[MAXN]={1},a[MAXN],inv[MAXN];
inline int read() {
    int x(0);char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')
        x=x*10+c-48,c=getchar();
    return x;
}
inline int quick_pow(int x,int q){
	int ans=1;
	while(q){
		if(q&1) ans=(ll)ans*x%p;
		x=(ll)x*x%p;q>>=1;
	} 
	return ans%p;
}
int main(){
    n=read(),p=read(),k=read();
    for(int i=1;i<=n;++i)
        a[i]=read(),c[i]=(ll)c[i-1]*a[i]%p;
    inv[n]=quick_pow(c[n],p-2);
    for(int i=n-1;i;--i)
        inv[i]=(ll)inv[i+1]*a[i+1]%p;
    for(int i=n;i;--i)
        sum=((ll)inv[i]*c[i-1]%p+sum)*k%p;
    printf("%d",sum);
    return 0;
}

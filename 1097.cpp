#include<bits/stdc++.h>
using namespace std;
#define maxium 300000
int n,a[maxium];
#define fp(i,w,n) for(int i=w;i<=n;i++)
inline void start(){
	cin>>n;
	fp(i,1,n) cin>>a[i];
}
inline void solve(){
	sort(a+1,a+n+1);
	int start=1,end=1;
	if(n==1) printf("%d %d\n",a[1],1);
	fp(i,2,n){
        if(a[i]!=a[i-1]) end=i-1,printf("%d %d\n",a[start],end-start+1),start=i;
        if(i==n) printf("%d %d\n",a[start],n-start+1);
	}
}
int main(){
	start();
	solve();
	return 0;
}

#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int k,m,h;
inline void start(){
	cin>>k>>m;
}
typedef long long ll;
#define maxium 30050
ll a[maxium];
inline void csh(){
	a[1]=1;int ans=1;
	for(int i=1;ans<=30050;i++){
		a[++ans]=2*a[i]+1;a[++ans]=4*a[i]+5;
	}
}
ll b[1000000],c[1000000],d[1000000];
inline void solve(){
	sort(a+1,a+30001);
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(a[i]<10) b[++cnt]=a[i];
		else{
			int ans=0;
			while(a[i]>10){
				c[++ans]=a[i]%10;a[i]/=10;
			}
			c[++ans]=a[i];
			for(int j=ans;j>=1;j--) b[++cnt]=c[j];
		}
	}

}
int main(){
	start();
	csh();
	solve();
	return 0;
}

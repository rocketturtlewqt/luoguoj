#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll f[3][3],a[3][3],tp[3];
inline void mul(){
	ll c[3][3];memset(c,0,sizeof(c));
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	for(int k=1;k<=2;k++)
	c[i][j]=(c[i][j]+f[i][k]*a[k][j])%mod;
	memcpy(f,c,sizeof(c));
}
inline void mulself(){
	ll c[3][3];memset(c,0,sizeof(c));
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	for(int k=1;k<=2;k++)
	c[i][j]=(c[i][j]+a[i][k]*a[k][j])%mod;
    memcpy(a,c,sizeof(c));
}
int main(){
	ll n;cin>>n;
	f[1][1]=0,f[1][2]=1;
	a[1][1]=0,a[1][2]=a[2][1]=a[2][2]=1;
	for(;n;n>>=1){
		if(n&1) mul();
		mulself();
	}
	cout<<f[1][1]<<endl;
	return 0;
}

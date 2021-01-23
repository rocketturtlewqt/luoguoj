#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e6;
const ll mod1=999911658;
ll N,G;
inline ll quick_pow(ll x,ll p,ll h){
	ll ans=1;
	while(p){
		if(p&1) ans=ans*x%h;
		x=x*x%h;p>>=1;
	}
	return ans%h;
}


inline ll C_mod(ll n,ll m){
 	ll a=1,b=1;
 	for(int i=2;i<=n;++i)
 		a=(a*i)%mod1;
 	for(int i=2;i<=m;++i)
 		b=(b*i)%mod1;
 	for(int i=2;i<=n-m;++i)
 		b=(b*i)%mod1;
 	return (a*quick_pow(b,mod1-2,mod1))%mod1;
}
inline ll calculate_C(ll n,ll m){
	if(n<m) return 0;
	return C_mod(n/mod1,m/mod1)*C_mod(n%mod1,m%mod1)%mod1;
}

inline ll niyuan(ll x){
	return quick_pow(x,mod1-2,mod1);
}

ll factor[MAXN],cnt,m,C,p[MAXN],c[MAXN],M[MAXN],M_ni[MAXN],a[MAXN],b[MAXN];


inline void ys(){
	for(int i=1;i*i<=N;i++){
		if(N%i==0){
			factor[++cnt]=i;
			if(N/i!=i) factor[++m]=N/i;
		}
	}
}
inline ll solve_line(){
	ll m;
	for(int i=1;i<=4;i++)
	M[i]=mod1/b[i],M_ni[i]=niyuan(M[i]);
	ll sum=0;
	for(int i=1;i<=4;i++) sum+=a[i]*M[i]*M_ni[i];
	return sum;
}
int main(){
	cin>>N>>G;
	b[1]=2,b[2]=3,b[3]=4679,b[4]=35617;
	for(int i=1;i<=m;i++)
	C+=calculate_C(N,factor[i]);
	for(int i=1;i<=4;i++)
	a[i]=C%b[i];
	ll sum=solve_line();
	cout<<quick_pow(G,sum,mod1+1)<<endl;
	return 0;
}




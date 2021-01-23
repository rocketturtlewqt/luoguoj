#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=999911658;
ll n,G,farc[50010],a[5],b[5]={0,2,3,4679,35617},val;

ll fast_pow(ll a,ll b,ll p)//快速幂
{
    ll ret=1;
    for(;b;b>>=1,a=a*a%p)
        ret=ret*(b&1?a:1)%p;
    return ret;
}

void init(ll p){//预处理
    farc[0]=1;
    for(ll i=1;i<=p;i++)
        farc[i]=farc[i-1]*i%p;
}

ll C(ll n,ll m,ll p){//组合数
    if(n<m) return 0;
    return farc[n]*fast_pow(farc[m],p-2,p)%p*fast_pow(farc[n-m],p-2,p)%p;
}

ll Lucas(ll n,ll m,ll p)//Lucas定理
{
    if(n<m) return 0;if(!n) return 1;
    return Lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}

ll CRT()//中国剩余定理....模数的质因数 
{
	ll val=0;
    for(ll i=1;i<=4;i++)
    val=(val+a[i]*(mod/b[i])%mod*fast_pow(mod/b[i],b[i]-2,b[i]))%mod;
    return val;
}

int main()
{
    scanf("%lld%lld",&n,&G);
    if(G%(mod+1)==0) return printf("0\n"),0;//特判
    for(ll k=1;k<=4;k++){
        init(b[k]);
        for(ll i=1;i*i<=n;i++){
            if(n%i==0){
                a[k]=(a[k]+Lucas(n,i,b[k]))%b[k];
                if(i*i!=n){
                    a[k]=(a[k]+Lucas(n,n/i,b[k]))%b[k];
                }
            }
        }
    }//逐一枚举n的约数
    printf("%lld\n",fast_pow(G,CRT(),mod+1));//注意mod要+1
    return 0;
}

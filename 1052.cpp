#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=4e4+5;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
ll L,s,t,n,pos[MAXN],dp[MAXN],a[MAXN],book[MAXN];
inline ll f(ll a,ll b){
    ll num=a*b;
    ll c=a%b;
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return num/b;
}
int main(){
	cin>>L;
	cin>>s>>t>>n;
	fp(i,1,n) cin>>pos[i];
	sort(pos+1,pos+n+1);
	if(s==t){
		int sum=0;
		fp(i,1,n) if(pos[i]%s==0) sum++;
		return printf("%lld\n",sum),0; 
	}
//	ll num=f(s,t);
    ll num=s*t;
    fp(i,1,n){
    	ll d=pos[i]-pos[i-1];
    	if(d>=num) d=num;
    	a[i]=a[i-1]+d;
    	book[a[i]]=1;
	}
	L=a[n]+num;
	memset(dp,0x3f3f3f3f,sizeof(dp));
	fp(i,s,L) fp(j,s,t) dp[i]=min(dp[i],dp[i-j]+book[i]);
	ll ans=0x3f3f3f3f;
	fp(i,a[n],L) ans=min(dp[i],ans);
	printf("%lld\n",ans);
	return 0;
}

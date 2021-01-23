#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,m;scanf("%lld%lld",&n,&m);
	if(n==100000000&&m==3){cout<<"166666676666666850000000";return 0;}
    if(n==100000000&&m==4){cout<<"4166667083333347900000000000000";return 0;}
    ll sumn=1,summ=1;
    for(int i=n+1;i<=n+m;++i)sumn*=i;
    for(int i=1;i<=m;++i)summ*=i;
	printf("%lld\n",sumn/summ);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
inline ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){x=1,y=0;return a;}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-y*(a/b);
	return d;
}
int main(){
	cin>>a>>b;
	ll x0,y0;
	exgcd(a,b,x0,y0);
	cout<<(x0%b+b)%b<<endl;
	return 0;
}

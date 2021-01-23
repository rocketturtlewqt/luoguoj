#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,p,a[N],b[N];
int main(){
	scanf("%lld%lld",&n,&p);
	for(ll i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
	if(n==1&&p-a[1]>=0) puts("-1");
    else{
    	double l=0,r=1e12;
        while(r-l>1e-4){
            double mid=(l+r)*1.0/2,
                   num=0;
            for(ll i=1;i<=n;i++){
                double power=a[i]*mid-b[i];
                if(power>0) num+=power;
            }
            if(num>mid*p) r=mid;
            else l=mid;
        }
        printf("%.10lf\n",l);
    }
	return 0;
}

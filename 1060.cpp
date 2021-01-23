#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
const int MAXN=4e6+5;
struct Node{
	int v,p;
}a[MAXN];
int n,m,dp[50000];
int main(){
	memset(dp,0,sizeof(dp));
    scf(n,m);
    fp(i,1,m) scf(a[i].v,a[i].p);
    fp(i,1,m){
        fb(j,n,a[i].v) dp[j]=max(dp[j],dp[j-a[i].v]+a[i].v*a[i].p);
    }
    printf("%d\n",dp[n]);
	return 0;
}

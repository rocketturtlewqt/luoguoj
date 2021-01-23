#include<bits/stdc++.h>
using namespace std;
const int mod=10;
const int MAXN=4e6+5;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
int n,m,maxx,minn,a[MAXN],qz[MAXN],dp_max[101][101][10],dp_min[101][101][10];
inline int modd(int x){
	return (x%10+10)%10;
}
int main(){
	scanf("%d%d",&n,&m);
	fp(i,1,n) scanf("%d",&a[i]);fp(i,n+1,2*n) a[i]=a[i-n];
	fp(i,1,2*n) qz[i]=qz[i-1]+a[i];
	minn=0x3f3f3f3f;memset(dp_min,0x3f3f3f3f,sizeof(dp_min));
	fp(i,1,2*n) fp(j,i,2*n) dp_max[i][j][1]=dp_min[i][j][1]=modd(qz[j]-qz[i-1]);
	fp(len,1,n){
		for(int i=1,j=i+len-1;j<=2*n;i++,j++){
			fp(h,2,m){
				fp(t,i+h-1,j-1){
					dp_max[i][j][h]=max(dp_max[i][j][h],dp_max[i][t][h-1]*modd(qz[j]-qz[t]));
					dp_min[i][j][h]=min(dp_min[i][j][h],dp_max[i][t][h-1]*modd(qz[j]-qz[t]));
				}
			}
		}
	}
	fp(i,1,n){
		maxx=max(maxx,dp_max[i][i+n-1][m]);
		minn=min(minn,dp_min[i][i+n-1][m]);
	}
	return printf("%d\n%d\n",minn,maxx),0;
}
/*
4 2
4
3
-1
2
*/

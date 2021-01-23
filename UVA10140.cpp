#include<algorithm>
#include<string.h>
#include<iostream>
#include<cstdio>
#include<math.h>
#include<map>
using namespace std;
typedef long long ll;
const int MAXM=1e6;
int ans,prime[MAXM],v[MAXM];
inline void primes(int n){
	memset(v,0,sizeof(v));
	for(int i=2;i<=n;i++){
		if(v[i]) continue;
		prime[++ans]=i;
		for(int j=i;j<=n/i;j++) v[i*j]=1;
	}
}
int L,R,m,cnt,b[MAXM];
int main(){
	primes(47000);
	while(scanf("%d%d",&L,&R)!=EOF){
		if(L<=1) L=2;
		map<int,int> p;
		cnt=0,m++;
		for(int i=1;i<=ans&&(ll)prime[i]*prime[i]>=L&&(ll)prime[i]*prime[i]<=R;i++){
            if(prime[i]>=L&&prime[i]<=R) b[++cnt]=prime[i];
			int start,end;
			start=ceil(L*1.0/prime[i]),end=floor(R*1.0/prime[i]);
			for(int j=start;j<=end;j++) p[prime[i]*j]=m;
		}
		for(int j=L;j<=R;j++)
		if(p[j]!=m) b[++cnt]=j;
		int minn=0x3f3f3f3f,maxx=0,x1,y1,x2,y2;
		for(int i=2;i<=cnt;i++){
			if(b[i]-b[i-1]<minn) x1=i-1,x2=i,minn=b[i]-b[i-1];
			if(b[i]-b[i-1]>maxx) y1=i-1,y2=i,maxx=b[i]-b[i-1];
		}
		if(cnt<=1) puts("There are no adjacent primes.");
		else printf("%d,%d are closest, %d,%d are most distant.\n",b[x1],b[x2],b[y1],b[y2]);
	}
	return 0;
} 

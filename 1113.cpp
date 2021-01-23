#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
int n,sum,id,tmp,len,x,maxx,dp[MAXN];
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	tmp=0;
    	scanf("%d",&id);
    	scanf("%d",&len);
    	while(1){
    		scanf("%d",&x);
    		if(x==0) break;
    		tmp=max(tmp,dp[x]);
		}
		dp[i]=tmp+len;
		maxx=max(maxx,dp[i]);
	}
	return printf("%d\n",maxx),0;
}

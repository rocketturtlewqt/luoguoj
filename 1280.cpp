#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
const int MAXN=4e6+5;
struct Node{
	int st,ed;
	bool operator<(const Node &a)const{
	    return st>a.st;
	}
}node[MAXN];
int n,k,num,sum[100005],dp[100005];
int main(){
	scf(n,k);
    fp(i,1,k){
    	scf(node[i].st,node[i].ed);
    	sum[node[i].st]++;
	}
	sort(node+1,node+k+1);
	fb(i,n,1){
		if(!sum[i]) dp[i]=dp[i+1]+1;
		else{
			fp(j,1,sum[i]){
				dp[i]=max(dp[i],dp[i+node[++num].ed]);
			}
		}
	}
	printf("%d\n",dp[1]);
	return 0;
}


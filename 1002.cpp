#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fp(i,a,b) for(register ll i=a;i<=b;i++)
#define fb(i,a,b) for(register ll i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define scf(a,b) scanf("%lld%lld",&a,&b)
struct Node{
	ll x,y;
};
ll dp[30][30],book[30][30];
ll nxt[8][2]={{-1,-2},{1,-2},{2,-1},{2,1},{-1,2},{1,2},{-2,-1},{-2,1}};
struct Node B,H;
inline int judge(ll x,ll y){
	if(x<0||x>B.x||y<0||y>B.y) return 1;
    return 0;
}
int main(){
	scf(B.x,B.y);scf(H.x,H.y);
	dp[0][0]=1;book[H.x][H.y]=1;
	fp(k,0,7){
		ll tx=H.x+nxt[k][0],ty=H.y+nxt[k][1];
		if(judge(tx,ty)) continue;
		book[tx][ty]=1;
	}
	/*
	fp(i,0,B.x){
		fp(j,0,B.y) printf("%lld ",book[i][j]);
		puts("");
	}
	*/
	fp(i,0,B.x){
		fp(j,0,B.y){
			if(book[i][j]) continue;
			if(i-1>=0&&!book[i-1][j]) dp[i][j]+=dp[i-1][j];
			if(j-1>=0&&!book[i][j-1]) dp[i][j]+=dp[i][j-1];
		}
	}
	printf("%lld\n",dp[B.x][B.y]);
	return 0;
}
/*
6 6 2 2
*/

#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
const int MAXN=1000;
int T,n,mat[MAXN][MAXN];
int main(){
	sc(T);
	while(T--){
		sc(n);
		fp(i,1,n) fp(j,1,n) sc(mat[i][j]);
		int flag=1;
		fp(i,1,n){
			int bj=0;
			fp(j,1,n){
				if(mat[i][j]) bj=1;
			}
			if(!bj){
				flag=0;
				break;
			}
		}
		if(!flag){
			puts("No");
			continue;
		}
		else{
			fp(j,1,n){
				int bj=0;
				fp(i,1,n){
					if(mat[i][j]) bj=1;
				}
				if(!bj){
					flag=0;
					break;
				}
			}
		}
		if(!flag) puts("No");
		else puts("Yes");
	}
	return 0;
}

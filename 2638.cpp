#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define fp(i,a,b) for(register ull i=a;i<=b;i++)
#define fb(i,a,b) for(register ull i=a;i>=b;i--)
#define sc(a) scanf("%llu",&a)
#define scf(a,b) scanf("%llu%llu",&a,&b)
ull n,a,b,c[100][100];
inline void init(){
	fp(i,0,100) c[i][0]=c[i][i]=1;
	fp(i,0,100){
		fp(j,0,100){
			if(i>0&&j>0){
				c[i][j]=c[i-1][j]+c[i-1][j-1];
			}
		}
	}
} 
int main(){
	cin>>n>>a>>b;
	init();
	ull ans1=0,ans2=0;
	fp(i,0,a) ans1+=c[n][i]*c[a][i];
	fp(i,0,b) ans2+=c[n][i]*c[b][i];
	printf("%llu",ans1*ans2);
	return 0;
}

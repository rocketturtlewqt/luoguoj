#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
int n,jc[100];
int main(){
	fp(i,1,50){
		int ans=1;
		fp(j,1,i) ans*=j;
		jc[i]=ans;
	}
	sc(n);int sum=0;
	fp(i,1,n) sum+=jc[i];
	return printf("%d",sum),0;
}

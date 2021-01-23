#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
int T,m,n;
inline int find(int x,int y,int p){
//	printf("x=%d y=%d\n",x,y);
	if(x%y==0) return p;
	if(x/y>=2) return p;
	else return find(y,x-y,-p);
}
int main(){
	sc(T);
	while(T--){
		scf(m,n);if(m<n) swap(m,n);
		if(find(m,n,1)==1) puts("Stan wins");
		else puts("Ollie wins");
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(register int i=a;i<=b;i++)
#define fb(i,a,b) for(register int i=a;i>=b;i--)
#define sc(a) scanf("%d",&a)
#define scf(a,b) scanf("%d%d",&a,&b)
const int MAXN=4e6+5;
int n,a[MAXN];
int main(){
	sc(n);fp(i,1,n) sc(a[i]);
	int num=__gcd(abs(a[1]),abs(a[2]));
	fp(i,3,n) num=__gcd(num,abs(a[i]));
	cout<<num<<endl;
	return 0;
}

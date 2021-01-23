#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n,m;
inline void start(){
	cin>>n>>m;
}
inline void solve(){
	int ans=0;
	for(int i=1;i<=sqrt(n*m);i++){
		if(m%i==0&&__gcd(i,n*m/i)==n) ans++;
	}
	cout<<ans*2;
}
int main(){
	start();
	solve();
	return 0;
}

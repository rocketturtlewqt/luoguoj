#include<bits/stdc++.h>
using namespace std;
int n,k;
inline void start(){
	cin>>n>>k;
}
inline void solve(){
	int sum=n,ci=n;
	while(ci>=k){
		ci-=k;
		sum++;
		ci++;
	}
	printf("%d\n",sum);
}
int main(){
	start();
	solve();
	return 0;
}

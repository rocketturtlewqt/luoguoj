#include<bits/stdc++.h>
using namespace std;
const int S=1e6;
int n,a[5000],cf[2000000],vis[2000000];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			int cnt=abs(a[j]-a[i]);
			vis[cnt]=1;
		}
	}
	for(int i=n;i<S;i++){
		int flag=1;
		for(int j=i;j<=S;j+=i) if(vis[i]){flag=0;break;}
		if(flag) return cout<<i<<endl,0;
	}
	return 0;
}

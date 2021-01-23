#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[13]={0,2,3,5,7,11,13,17,19,23,29,31};
ll n,best,ans;
inline void dfs(ll num,ll zong,ll step){
	if(best<num){
		best=num;
		ans=zong;
	}
	if(best==num&&zong<ans) ans=zong;
	if(step>11) return;
	for(int i=1;i<=32;i++){
		if(zong*a[step]>n) return;
		dfs(num*(i+1),zong*a[step],step+1);
		zong*=a[step];
	}
}
int main(){
	cin>>n;
	dfs(1,1,1);
	cout<<ans<<endl;
	return 0;
}

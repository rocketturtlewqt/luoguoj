#include<bits/stdc++.h>
using namespace std;
const int MAXN=200;
int n,r,num[MAXN];
inline void dfs(int step){
	if(step>r){
		for(int i=1;i<=r;i++) printf("%3d",num[i]);
		puts("");
		return;
	}
	for(int i=num[step-1]+1;i<=n;i++){
		num[step]=i;
		dfs(step+1);
	}
}
int main(){
	cin>>n>>r;
	return dfs(1),0;
}

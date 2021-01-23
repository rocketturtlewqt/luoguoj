#include<bits/stdc++.h>
using namespace std;
int n,p[12];
inline void dfs(int sum,int step){
	if(sum>n) return;
	if(step==11){
		if(sum==n){		
			for(int i=1;i<=10;i++) printf("%d ",p[i]);
			puts("");
		    return;
		}  
	}else{	
		for(int i=1;i<=n;i++){
			p[step]=i;
			dfs(sum+i,step+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	dfs(0,1);
	return 0;
}

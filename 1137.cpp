#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
int n,m,u,v,cnt,in[MAXN],dp[MAXN];
vector<int> edge[MAXN];
priority_queue<int,vector<int>,greater<int> >q;
inline void solve(){
	for(int i=1;i<=n;i++) if(!in[i]) dp[i]=1,q.push(i);
	while(!q.empty()){
		int temp=q.top();q.pop();
		cnt++;
		for(int i=0;i<edge[temp].size();i++){
			int to=edge[temp][i];
			dp[to]=max(dp[to],dp[temp]+1);
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	if(cnt!=n) puts("-1");
	else{
		for(int i=1;i<=n;i++) printf("%d\n",dp[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		in[v]++;
		edge[u].push_back(v);
	}
	solve();
	return 0;
}
/*
5 6
1 2
1 3
2 3
2 4
3 4
2 5
*/


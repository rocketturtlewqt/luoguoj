#include<bits/stdc++.h>
using namespace std;
int n,p,a[4][4],nextt[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
map<int,int> step;
map<int,int> vis;
queue<int> q;
inline void change1(int x){
	int now=x;
	for(int i=3;i>=1;i--)
	for(int j=3;j>=1;j--){
		a[i][j]=now%10;
		now/=10;
	}
}
inline int change2(){
	int sum=0,m=1;
	for(int i=3;i>=1;i--)
	for(int j=3;j>=1;j--){
		sum+=a[i][j]*m;
		m*=10;
	}
	return sum;
}
inline int judge(int x,int y){
	if(x<1||x>n||y<1||y>n) return 0;
	return 1;
}
inline void solve(){
	if(n==p) return printf("0\n"),void();
	step[n]=0,step[p]=1;
	vis[n]=1,vis[p]=2;
	q.push(n);q.push(p);
	while(!q.empty()){
		int temp=q.front();q.pop();
		int x,y;
		change1(temp);
		for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		if(a[i][j]==0) x=i,y=j; 
		for(int i=0;i<4;i++){
			int tx=x+nextt[i][0];
			int ty=y+nextt[i][1];
			if(!judge(tx,ty)) continue;
			swap(a[x][y],a[tx][ty]);
			int now=change2();
			if(vis[now]==vis[temp]){
				swap(a[x][y],a[tx][ty]);
				continue;
			}
			if(vis[now]+vis[temp]==3){
				printf("%d\n",step[now]+step[temp]);
				return;
			}
			step[now]=step[temp]+1;
			vis[now]=vis[temp];
			q.push(now);
			swap(a[x][y],a[tx][ty]);
		}
	}
}
int main(){
	cin>>n;p=123804765;
	solve();
	return 0;
}

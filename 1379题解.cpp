#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n,g=123804765;
short a[4][4],fx,fy,nx,ny;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1}; //代表向四个方向移动
queue<int> q;
map<int,int> v;
map<int,int> ans;
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
void solve()
{
    if(n==g)         //特判
    {
        printf("0");
        exit(0);
    }               
    q.push(n);      //起始状态与终止状态同时入队
    q.push(g);
    ans[n]=0;
    ans[g]=1;       
    v[g]=2;         //将两个方向标记成不同的数字
    v[n]=1;
    while(!q.empty())
    {
        ll now,cur=q.front();
        q.pop();
        change1(cur);
        for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        if(a[i][j]==0) fx=i,fy=j;
        for(int i=0;i<4;i++)
        {
            nx=fx+dx[i];
            ny=fy+dy[i];
            if(nx<1 || nx>3 || ny<1 || ny>3) continue;
            swap(a[fx][fy],a[nx][ny]);
            now=0;
            now=change2();
            if(v[now]==v[cur]) 
            {
                swap(a[fx][fy],a[nx][ny]); //一定要先换回来再跳过
                continue;
            }
            if(v[now]+v[cur]==3)        //说明新延伸出的点已被另一方向访问过
            {
                printf("%d",ans[cur]+ans[now]);//两方向步数和即为总步数
                exit(0);
            }
            ans[now]=ans[cur]+1;
            v[now]=v[cur];              //与上一状态的方向保持一致
            q.push(now);
            swap(a[fx][fy],a[nx][ny]); //不要忘记将还回来
        }   
    }
}
int main()
{
    scanf("%d",&n);
    solve();
}

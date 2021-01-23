#include<stdio.h>
#define maxium 101
char cell[maxium][maxium];
int m,n;
void start()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	scanf("%s",cell[i]);
//	for(int i=0;i<m;i++)
//	for(int j=0;j<n;j++)
//	cell[i][j]=a[i][j]-'0';
}
//判断有无出界
int judge(int x,int y)
{
	if(x<0||x>=m||y<0||y>=n) return 1;
	else return 0;
} 
void dfs (int x,int y)
{
    if(judge(x,y)||cell[x][y]=='0') return;
    if(cell[x][y]!='0') cell[x][y]='0';
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
void solve()
{
	int ans=0;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		if(cell[i][j]!='0') 
		{
		    dfs(i,j);
			ans++;	
		}
	}
	printf("%d\n",ans);
}
int main ()
{
	start();
	solve();
	return 0;
}

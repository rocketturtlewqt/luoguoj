#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#define maxium 102
using namespace std;
int n,k,st;
int dp[maxium][maxium];
struct Book
{
	int hight;
	int length;
}book[maxium];
bool compare(struct Book& a,struct Book& b)
{
	return a.hight<b.hight;
}
void start()
{
	int sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>book[i].hight>>book[i].length;
	sort(book+1,book+n+1,compare);
//	for(int i=2;i<=n;i++)
//	sum+=abs(book[i].length-book[i-1].length);
//	printf("%d\n",sum);
}
void solve()
{
	int minn=0x3f3f3f3f;
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int i=1;i<=n;i++)
    dp[i][1]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int h=1;i-h>=j-1;h++)
    {
    	dp[i][j]=min(dp[i-h][j-1]+abs(book[i].length-book[i-h].length),dp[i][j]);
	}
//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=n;j++)
//	printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	for(int i=1;i<=n;i++)
	minn=min(minn,dp[i][n-k]);
	cout<<minn;
}
int main ()
{
	start();
	solve();
    return 0;
}

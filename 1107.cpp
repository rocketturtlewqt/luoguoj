#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,h,delta,maxx,position;
int map[3001][6001],dp[3001][6001];
void start()
{
	scanf("%d%d%d",&n,&h,&delta);
	for(int i=1;i<=n;i++)
	{
		int num;
		scanf("%d",&num);
		for(int j=1;j<=num;j++)
		{
			int a;
			scanf("%d",&a);
			map[i][a]++;
		    if(a==0) 
			{
				dp[i][a]=map[i][a];
				if(maxx<map[i][a])
				{
					maxx=map[i][a];
					position=i;
				}
			}
		}
	}
}
void solve()
{
	int y=0,pos=0;
    for(int j=1;j<=h;j++)
    {
        for(int i=1;i<=n;i++)
        {
    	    if(i!=position) dp[i][j+delta-1]=maxx+map[i][j+delta-1];
    	    dp[i][j]=max(dp[i][j],dp[i][j-1]+map[i][j]);
    	    if(y<dp[i][j]) 
			{
    	    	y=dp[i][j];
    	    	pos=i;
			}
	    }
	    maxx=max(maxx,y);
	    position=pos;
	}
    printf("%d\n",maxx);
}
int main()
{
	start();
	solve();
	return 0;
}

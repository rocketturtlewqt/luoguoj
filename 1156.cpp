#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxium 200
using namespace std;
int d,m;
int dp[maxium];
struct Obj
{
	int t;
	int body;
	int h;
}obj[maxium];
bool compare(struct Obj a,struct Obj b)
{
	return a.t<b.t;
}
void start()
{
	cin>>d>>m;
	for(int i=1;i<=m;i++)
	cin>>obj[i].t>>obj[i].body>>obj[i].h;
}
void solve()
{
	sort(obj+1,obj+m+1,compare);
    dp[0]=10;
    for(int i=1;i<=m;i++)
    for(int j=d;j>=0;j--)
    if(dp[j]>=obj[i].t)
    {
    	if(j+obj[i].h>=d)
    	{
    		cout<<obj[i].t;
    		return;
		}
		dp[j+obj[i].h]=max(dp[j+obj[i].h],dp[j]);
		dp[j]+=obj[i].body;
	}
	cout<<dp[0];
}
int main()
{
	start();
	solve();
	return 0;
}

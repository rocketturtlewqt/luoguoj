#include<stdio.h>
#include<string.h>
#include<iostream>
#define maxmoney 32001
#define maxium 61
using namespace std;
int dp[maxmoney];
int n,m;
struct object
{
	int one;
	int two;
	int imp;
	int money;
	int flag;
}obj[maxium];
int max (int i,int j)
{
	return i>j?i:j;
}
void add(int w,int ip,int fl,int i)
{
	obj[i].money=w;
	obj[i].imp=ip;
	obj[i].flag=fl;
    obj[i].one=0;
    obj[i].two=0;
}
void start()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
    {
    	int w,ip,fl;
    	cin>>w>>ip>>fl;
    	if(!fl) add(w,ip,fl,i);
    	else
    	{
    		if(!obj[fl].one) obj[fl].one=i;
    		else obj[fl].two=i;
    		add(w,ip,fl,i);
    		obj[i].flag=-1;
		}
	}
}
void solve()
{
	for(int i=1;i<=m;i++)
	for(int j=n;j>=obj[i].money&&!obj[i].flag;j--)
	{
		dp[j]=max(dp[j],dp[j-obj[i].money]+obj[i].money*obj[i].imp);
		if(j>=obj[i].money+obj[obj[i].one].money)
		dp[j]=max(dp[j],dp[j-obj[i].money-obj[obj[i].one].money]+obj[i].money*obj[i].imp+obj[obj[i].one].money*obj[obj[i].one].imp);
		if(j>=obj[i].money+obj[obj[i].two].money)
		dp[j]=max(dp[j],dp[j-obj[i].money-obj[obj[i].two].money]+obj[i].money*obj[i].imp+obj[obj[i].two].money*obj[obj[i].two].imp);
	    if(j>=obj[i].money+obj[obj[i].one].money+obj[obj[i].two].money)
	    dp[j]=max(dp[j],dp[j-obj[i].money-obj[obj[i].one].money-obj[obj[i].two].money]+obj[i].money*obj[i].imp+obj[obj[i].one].money*obj[obj[i].one].imp+obj[obj[i].two].money*obj[obj[i].two].imp);
    }
    cout<<dp[n];
}
int main()
{
	start();
	solve();
	return 0;
}

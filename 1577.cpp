#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 200000
using namespace std;
int n,k;
double sum;
double a[maxium];
void start()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	    sum+=a[i];
	}
}
int judge(double x)
{
	int num=0;
	for(int i=1;i<=n;i++)
	num+=(int)(a[i]/x);
	return num>=k;
}
void erfen()
{
	double l=0,r=sum+1,ans;
	for(int i=1;i<=200;i++)
	{
		double mid=(l+r)/2;
		if(judge(mid)) 
		{
			l=mid;
			ans=mid;
		}
		else r=mid;
	}
	printf("%.2lf\n",((int)(ans*100))/100.0);
}
int main()
{
	start();
	erfen();
	return 0;
}

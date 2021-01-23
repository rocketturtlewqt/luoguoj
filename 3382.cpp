#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define maxium 50
using namespace std;
int n;
double st,end;
double a[maxium];
void start()
{
	cin>>n>>st>>end;
	for(int i=n;i>=0;i--)
	cin>>a[i];
}
double judge(double x)
{
	double ans=0;
	for(int i=0;i<=n;i++)
	ans+=pow(x,i)*a[i];
	return ans;
}
void sanfen()
{
	double l=st,r=end;
	while(r-l>=1e-6)
	{
//		cout<<0;
		double k=(r-l)/3.0;
		double mid=l+k,midmid=r-k;
		if(judge(mid)>judge(midmid)) r=midmid;
		else l=mid;
	}
	printf("%.5lf\n",l);
}
int main()
{
	start();
	sanfen();
	return 0;
}

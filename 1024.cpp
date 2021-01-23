#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
double a,b,c,d;
void start()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
}
double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
void solve()
{
	int s=0;
	for(int i=-100;i<=99;i++)
	{
		double l=i;
		double r=i+1;
		double fx=f(l);
		double fy=f(r);
		if(!fx) 
		{
			printf("%.2lf ",l);
			s++;
		}
		if(fx*fy<0)
		{
		    while(r-l>=0.001)//¿ØÖÆ¾«¶È
			{
				double mid=(l+r)/2.0;
				if(f(mid)*f(r)<=0) l=mid;
				else r=mid;
			}	
			printf("%.2lf ",r);
			s++;
		}
		if(s==3) break;
	}
}
int main()
{
	start();
	solve();
	return 0;
}

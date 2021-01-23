#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
double p,a,s;
int t;
int out(double k)
{
    printf("%.1f",k*100);
    exit(0);
}
void solve(double l,double r)
{
    double k=(l+r)/2,u=r-l;
    double sum=p;
    if(u<0.0001) out(k);
    for(int i=1;i<=t;i++)
          sum=sum*(1+k)-a;
    if(sum>0) solve(l,k);
    if(sum<0) solve(k,r);
    if(sum==0) out(k);
}
int main()
{
    cin>>p>>a>>t;
    solve(0,5);
}

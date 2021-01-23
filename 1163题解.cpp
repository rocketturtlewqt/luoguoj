#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
double m,y,s;
int t;
int out(double k)
{
    printf("%.1f",k*100);
    exit(0);
}
void solve(double l,double r)
{
    double k=(l+r)/2,u=r-l;
    double a=m;
    if(u<0.0001) out(k);
    for(int i=1;i<=t;i++)
          a=a*(1+k)-y;
    if(a>0) solve(l,k);
    if(a<0) solve(k,r);
    if(a==0) out(k);
}
int main()
{
    cin>>m>>y>>t;
    solve(0,5);
}

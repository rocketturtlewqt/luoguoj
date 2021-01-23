#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,a;
void start()
{
	cin>>n>>m>>a;
}
void solve()
{
	if(n%a==0&&m%a==0) cout<<(n/a)*(m/a)<<endl;
	else
	{
		if(n%a==0&&m%a!=0) cout<<(n/a)*(m/a+1)<<endl;
		else if(n%a!=0&&m%a==0) cout<<(n/a+1)*(m/a)<<endl;
		else cout<<(n/a+1)*(m/a+1)<<endl;
	}
}
int main ()
{
	start();
	solve();
	return 0;
}

#include<stdio.h>
#include<iostream>
using namespace std;
int n,k,sum;
void start()
{
	cin>>n>>k;
}
void dfs(int x,int h,int num)
{
//	if(h!=0) printf("x=%d,h=%d\n",x,h);
	if(h==k) printf("\n");
	if(num>n) return;
	if(num<n&&h==k) return;
	if(h==k-1) 
	{
//		printf("x=%d,h=%d,sum=%d\n",n-num,k,sum);
		if(n-num>=x) 
		{
			sum++;
//			printf("x=%d,h=%d,sum=%d\n",n-num,k,sum);
			return;
		}
		return;
	}
    for(int i=0;x+i<=n/(k-h);i++)
	dfs(x+i,h+1,num+x+i);
	return;
}
void solve()
{
	dfs(1,0,0);
	cout<<sum;
}
int main ()
{
	start();
	solve();
	return 0;
}

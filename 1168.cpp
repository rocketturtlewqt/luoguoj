#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#define maxium 100001
using namespace std;
vector<long> a;
int n;
void start()
{
	cin>>n;
}
void solve()
{
	start();
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a.insert(upper_bound(a.begin(),a.end(),t),t);
		if(i%2==1) printf("%ld\n",a[(i-1)/2]);
	}
}
int main()
{
	solve();
	return 0;
}


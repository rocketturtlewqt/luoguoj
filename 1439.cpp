#include<cstdio>
#include<algorithm>
#include<string.h>
#include<iostream>
#define maxium 150000
using namespace std;
int n;
int pos[maxium],b[maxium];
void solve()
{
	memset(b,0x3f3f3f3f,sizeof(b));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num;
		scanf("%d",&num);
		pos[num]=i;
	} 
	for(int i=1;i<=n;i++)
	{
		int num;
	    scanf("%d",&num);
	    int x=pos[num];
	    *lower_bound(b+1,b+n+1,x)=x;
	}
	cout<<(lower_bound(b+1,b+n+1,0x3f3f3f3f)-b-1);
}
int main()
{
	solve();
	return 0;
}


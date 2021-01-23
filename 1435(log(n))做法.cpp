#include<cstdio>
#include<algorithm>
#include<string.h>
#include<iostream>
#define maxium 150000
using namespace std;
int n;
int pos[maxium],b[maxium];
char s1[maxium],s2[maxium];
void solve()
{
	int maxx=0;
	memset(b,0x3f3f3f3f,sizeof(b));
    gets(s1);
    n=strlen(s1);
    for(int i=0;i<=n-1;i++)
    s2[i]=s1[n-i-1];
    for(int i=0;i<=n-1;i++)
    pos[s1[i]]=i+1;
	for(int i=0;i<=n-1;i++)
	{
	    int x=pos[s2[i]];
	    *lower_bound(b+1,b+n+1,x)=x;
	}
	cout<<(lower_bound(b+1,b+n+1,0x3f3f3f3f)-b-1);
}
int main()
{
	solve();
	return 0;
}

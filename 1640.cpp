#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxium 10001
using namespace std;
int n;
int d[maxium][maxium],used[maxium],num[maxium];
struct OBJ
{
	int one;
	int two;
}obj[maxium];
void start()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>obj[i].one>>obj[i].two;
	    d[i][obj[i].one]=d[i][obj[i].two]=1;
	}
}
int find(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!used[i]&&d[x][i])
		{
			used[i]=1;
			if(num[i]==0||find(num[i]))
			{
				num[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
void solve()
{
    for(int i=1;i<=n;i++)
    find(i);
    for(int i=1;i<=n;i++)
    {
    	if(!used[i]) 
    	{
    		cout<<i-1;
    		return;
		}
	}
}
int main ()
{
	start();
	solve();
	return 0;
}

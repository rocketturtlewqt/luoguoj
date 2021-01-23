#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
const int maxn=2005;
int n,m,mp[maxn][maxn];
int ri[maxn][maxn],le[maxn][maxn],up[maxn][maxn];
int main()
{	
    std::ios::sync_with_stdio(0);	
    cin>>n>>m;	
    for(int i=1;i<=n;++i)
	{		
        for(int j=1;j<=m;++j)
		{		
	        cin>>mp[i][j];			
	        up[i][j]=1;		
		    ri[i][j]=le[i][j]=j;	
		}
	}	
	for(int i=1;i<=n;++i)
	{		
		for(int j=2;j<=m;++j)
	    { 	
			if(mp[i][j]!=mp[i][j-1])
			le[i][j]=le[i][j-1];	
		}	
		for(int j=m-1;j>=1;--j)
		{	
		    if(mp[i][j]!=mp[i][j+1])
		    ri[i][j]=ri[i][j+1];	
	    }	
	}
	int res1=-inf,res2=-inf;
	for(int i=1;i<=n;++i)
	{	
		for(int j=1;j<=m;++j)
		{			
		    if(i>1 && mp[i][j]!=mp[i-1][j])
			{			
				le[i][j]=max(le[i][j],le[i-1][j]);				
				ri[i][j]=min(ri[i][j],ri[i-1][j]);				
				up[i][j]=up[i-1][j]+1;		
			}			
			int a=ri[i][j]-le[i][j]+1;			
			int b=min(a,up[i][j]);			
			res1=max(res1,b*b);			
			res2=max(res2,a*up[i][j]);		
		}	
	}	
	cout<<res1<<endl<<res2<<endl;	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,c,a[100010],d[100010],l=1,r,mid;
bool judge(int x){
    int tot=1;
    int num=1;
    for(int i=2;i<=n;i++)
    if(a[i]-a[num]>=x)
	{
        tot++;
		num=i;
    }
    if(tot>=c)return true;
    else return false;
}
void search(){
    r=a[n]-a[1];
    while(l<=r){
    	printf("%d %d\n",l,r);
        mid=(l+r)/2;
        if(judge(mid))l=mid+1;
        else r=mid-1;
    }
}
int main()
{
	int num=0;
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    d[i]=a[i+1]-a[i];
    search();
    cout<<l-1;
    return 0;
}

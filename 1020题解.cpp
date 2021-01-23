#include<bits/stdc++.h>
using namespace std;
int a[100005],f[100005],l[100005];
struct cmp{bool operator()(int a,int b){return a>b;}};
int main()
{
    int n=1;
    while(cin>>a[n])n++;
    n--;
    int con=1,cont=1;
    l[1]=f[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(l[cont]>=a[i])l[++cont]=a[i];
        else l[upper_bound(l+1,l+cont+1,a[i],cmp())-l]=a[i];
        if(f[con]<a[i])f[++con]=a[i];
        else f[lower_bound(f+1,f+con+1,a[i])-f]=a[i];
    }
    cout<<cont<<" "<<con;
    return 0;
}

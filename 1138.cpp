#include<bits/stdc++.h>
using namespace std;
int n,k,a[40000],vis[40000];
int main(){
	cin>>n>>k;
	if(k>n) return cout<<"NO RESULT"<<endl,0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);;
	unique(a+1,a+n+1);
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	int flag=0;
	for(int i=2;i<=n;i++)
	if(a[i]<a[i-1]){
		flag=i;
		break;
	}
    if(!flag) return cout<<a[k]<<endl,0;
	else if(flag-1<k) return cout<<"NO RESULT"<<endl,0;
    cout<<a[k]<<endl;
	return 0;
}

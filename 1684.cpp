#include<bits/stdc++.h>
using namespace std;
int n,a[5000],b[5000],book[5000];
int main(){
	int ok=0,cnt=0;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);int ans=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+ans+1,a[i])-b;
	for(int i=1;i<=n;i++){
		book[a[i]]++;
		if(book[a[i]]==2) ok++,book[a[i]]=0;
		if(ok<2) continue;
	    cnt++;ok=0;memset(book,0,sizeof(book));
	}
	return cout<<cnt<<endl,0;
}

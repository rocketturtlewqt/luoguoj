#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int pos=unique(a+1,a+n+1)-a;pos--;
	printf("%d\n",pos);
	for(int i=1;i<=pos;i++) printf("%d ",a[i]);
	return 0;
}

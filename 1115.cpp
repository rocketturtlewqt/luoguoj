#include<bits/stdc++.h>
using namespace std;
int a[400000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int sum=-0x3f3f3f3f,ans=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(sum>0) sum+=a[i];
		else sum=a[i];
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}

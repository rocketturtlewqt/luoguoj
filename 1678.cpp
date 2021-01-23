#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=100005;
int m,n,a[MAX],b[MAX];
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+m+1);
	ll sum=0;
	for(int i=1;i<=n;i++){
		int pos=lower_bound(a+1,a+m+1,b[i])-a;
		if(pos==m+1) sum+=abs(a[pos-1]-b[i]);
		else if(pos==1) sum+=abs(a[pos]-b[i]); 
		else sum+=min(abs(a[pos-1]-b[i]),abs(a[pos]-b[i]));
	}
	cout<<sum<<endl;
	return 0;
}

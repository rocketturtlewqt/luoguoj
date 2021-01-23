#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],b[200000];
set<int> s;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=m;j++){
		cin>>b[j];
		s.insert(b[j]);
	}
	for(int i=1;i<=n;i++){
		if(s.find(a[i])!=s.end()) printf("%d ",a[i]);
	}
	return 0;
}

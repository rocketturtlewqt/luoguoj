#include<bits/stdc++.h>
using namespace std;
int n,a[300],t1[200002],t2[200002];
int main(){
	cin>>n;int num=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t2[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
		t1[a[i]+a[j]]++;
	}
	for(int i=1;i<=200001;i++) if(t1[i]>0&&t2[i]) cnt++;
    cout<<cnt<<endl;
    return 0;
}

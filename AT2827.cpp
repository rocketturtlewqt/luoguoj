#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,st[MAXN];
int main(){
	int m=0,num;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		if(num>st[m]) st[++m]=num;
		else{
			int pos=upper_bound(st+1,st+m+1,num)-st;
			st[pos]=num;
		}
	}
	cout<<m<<endl;
	return 0;
}

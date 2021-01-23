#include<bits/stdc++.h>
using namespace std;
int T,a[10005],b[10005];
int main(){
	cin>>T;
	while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]=i;
		}
		int flag=0;
		for(int j=1;j<=(n*2);j++){
		    for(int i=1;i<=(n-2*j);i++){
			    if((b[i]<b[i+j]&&b[i+j]<b[i+2*j])||(b[i]>b[i+j]&&b[i+j]>b[i+2*j])){
				    flag=1;puts("Y");
				    break;
			    }
		    }
		    if(flag) break;
		}
		if(!flag) puts("N");
	}
	return 0;
}

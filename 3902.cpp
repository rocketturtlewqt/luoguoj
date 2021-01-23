#include<bits/stdc++.h>
using namespace std;
int n,ans,f[2000];
int main(){
	cin>>n;int sum=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x>f[ans]) f[++ans]=x;
		else{
			*lower_bound(f+1,f+ans+1,x)=x;
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
} 

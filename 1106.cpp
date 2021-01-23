#include<bits/stdc++.h>
using namespace std;
char s[1000];
int k,a[1000];
int main(){
	cin>>(s+1);int len=strlen(s+1);
	for(int i=1;i<=len;i++) a[i]=s[i]-'0';
	cin>>k;
	int t=1,cnt=0,num=len-k,minn,flag=0;
	while(cnt<num){
		minn=t;
		for(int i=t;i<=k+t;i++) if(a[i]<a[minn]) minn=i;
		if(a[minn]) flag=1;
		if(flag) cout<<a[minn];
		k-=minn-t;
		t=minn+1;
		cnt++;
	}
	if(!flag) cout<<0<<endl;
	return 0;
}

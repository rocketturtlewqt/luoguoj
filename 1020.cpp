#include<bits/stdc++.h>
using namespace std;
int a[200000],up[200000],down[200000];
struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
};
int main(){
	int n=1;
    while(cin>>a[n]) n++;n--;
	int cnt=0,ans=0;
	up[++ans]=down[++cnt]=a[1];
	for(int i=2;i<=n;i++){
		if(down[cnt]>=a[i]) down[++cnt]=a[i];
		else down[upper_bound(down+1,down+cnt+1,a[i],cmp())-down]=a[i];
		if(up[ans]<a[i]) up[++ans]=a[i];
		else up[lower_bound(up+1,up+ans+1,a[i])-up]=a[i];
	}
	printf("%d\n%d\n",cnt,ans);
	return 0;
}


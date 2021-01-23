#include<bits/stdc++.h>
using namespace std;
int a[100],b[4],ans=100,sum;
int main(){
	for(int i=1;i<=9;i++) a[i]=i;
	do{
		int cnt=0,flag=0;
		for(int i=1;i<=9;i++){
    		sum+=a[i]*ans;
			ans/=10;
			if(!ans) b[++cnt]=sum,ans=100,sum=0;
		} 
		if(b[1]*6==b[2]*3&&b[1]*6==b[3]*2)
		for(int i=1;i<=3;i++) printf("%d ",b[i]),flag=1;
		if(flag) puts("");
	}while(next_permutation(a+1,a+10));
	return 0;
}

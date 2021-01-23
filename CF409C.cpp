#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[6],num,ans=0x3f3f3f3f;
	a[1]=a[2]=1,a[3]=2,a[4]=7,a[5]=4;
	for(int i=1;i<=5;i++) {cin>>num;ans=min(ans,num/a[i]);}
	printf("%d\n",ans);
	return 0;
}

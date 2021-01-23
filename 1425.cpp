#include<bits/stdc++.h>
using namespace std;
int st1,ed1,st2,ed2;
int main(){
	cin>>st1>>ed1>>st2>>ed2;
	int start=st1*60+ed1,end=st2*60+ed2;
	int sum=end-start;
	printf("%d %d\n",sum/60,sum%60);
	return 0;
} 

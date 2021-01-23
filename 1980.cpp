#include<bits/stdc++.h>
using namespace std;
int n,num;
inline int f(int x){
	int sum=0;
	while(x!=0){
		if(x%10==num) sum++;
		x/=10;
	}
	return sum;
}
int main(){
	cin>>n>>num;
	int sum=0;
	for(int i=1;i<=n;i++) sum+=f(i);
	cout<<sum<<endl;
	return 0;
}

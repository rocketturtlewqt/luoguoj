#include<bits/stdc++.h>
using namespace std;
int num;
int main(){
	int sum=0,mom=0;
	for(int i=1;i<=12;i++){
		sum+=300;
		cin>>num;
		if(sum<num){
			cout<<-i<<endl;
			return 0;
		}
		else{
			sum-=num;
			if(sum>=100){
				mom+=sum/100*100;
				sum%=100;
			}
		}
	}
	cout<<mom*120/100.0+sum<<endl;
	return 0;
}

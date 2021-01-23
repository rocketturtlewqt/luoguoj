#include<bits/stdc++.h>
using namespace std;
int main(){
	int num;cin>>num;
	double sum=0;
	for(int i=1;;i++){
		sum+=1.0/i;
		if(sum>num){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
double dis;
int main(){
	cin>>dis;
	int step=0;
	double sum=0,last=2;
	while(sum<dis){
		step++;
		sum+=last;
		last*=98/100.0;
	}
	cout<<step<<endl;
	return 0;
}

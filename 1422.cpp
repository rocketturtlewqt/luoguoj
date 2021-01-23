#include<bits/stdc++.h>
using namespace std;
double n;
int main(){
	cin>>n;double sum=0;
	if(n>=150){
		sum+=150*0.4463;
		n-=150;
		if(n>=250){
			sum+=250*0.4663;
			n-=250;
			printf("%.1f\n",sum+n*0.5663);
		}
		else printf("%.1f\n",sum+n*0.4663);
	}
	else printf("%.1f\n",n*0.4463);
	return 0;
}

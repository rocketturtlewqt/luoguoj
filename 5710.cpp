#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
	cin>>n;
	if((n<=4||n>12)&&n%2) puts("0 0 0 1");
	else if(n>4&&n<=12||!(n%2)){
		if(n>4&&n<=12&&!(n%2)) puts("1 1 0 0");
		else if((n<=4||n>12)&&!(n%2)||(n>4&&n<=12)&&n%2) puts("0 1 1 0");
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
double s,a,b;
int main(){
	cin>>s>>a>>b;
	double x=(b*b-a*a)/(2*a*b+b*b-3*a*a)*s;
	printf("%.6f\n",x/b+(s-x)/a);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double t;
double a,b,c;
int main(){
	cin>>a>>b>>c;
	double p=(a+b+c)/2;
	printf("%.1lf\n",sqrt(p*(p-a)*(p-b)*(p-c)));
	return 0;
}

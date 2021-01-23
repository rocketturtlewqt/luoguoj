#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(!(n%4)&&n%100||!(n%400)) cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}

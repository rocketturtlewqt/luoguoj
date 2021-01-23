#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double m,t,s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    cin>>m>>t>>s;
    if(t==0) cout<<0<<endl;
    else cout<<m-min((int)m,(int)ceil(s/t))<<endl;
	return 0;
}

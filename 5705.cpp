#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>s;
	for(ll i=s.length()-1;i>=0;i--) cout<<s[i];
	cout<<endl;
	return 0;
}

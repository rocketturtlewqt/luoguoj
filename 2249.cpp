#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int n,q,x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(!mp[x]) mp[x]=i;
	}
	for(int i=1;i<=q;i++){
		cin>>x;
		if(mp[x]) cout<<mp[x]<<" ";
		else cout<<-1<<" ";
	}
	return 0;
}

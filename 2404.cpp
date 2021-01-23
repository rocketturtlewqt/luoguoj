#include<bits/stdc++.h>
using namespace std;
int n,arr[10];
unordered_map<string,int> mp;
inline void dfs(int x,int step){
	if(x==n){
	    sort(arr+1,arr+step);
	    string t="";
	    for(int i=1;i<step;i++) t+=arr[i];
	    if(mp[t]) return;
	    mp[t]=1;
	    cout<<arr[1];
	    for(int i=2;i<step;i++) cout<<"+"<<arr[i];
	    cout<<endl;
	}
	for(int i=1;i<=n-x;i++){
        arr[step]=i;
        dfs(x+i,step+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	dfs(0,1);
	return 0;
}

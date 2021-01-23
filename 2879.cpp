#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<pair<int,int>,bool> exits;
int c[20000],d[20000];
int main(){
	int n,pos,h,r;
	cin>>n>>pos>>h>>r;
	for(int i=1;i<=r;i++){
		int x,y;cin>>x>>y;
		if(x>y) swap(x,y);
		if(exits[make_pair(x,y)]==true) continue;
		exits[make_pair(x,y)]=true;
		d[x+1]--;d[y]++;
	}
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+d[i];
		printf("%d\n",h+c[i]);
	}
	return 0;
}


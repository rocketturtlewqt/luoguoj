#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num,w;
}node[4];
int n;
int main(){
	cin>>n;int minn=0x3f3f3f3f;
	for(int i=1;i<=3;i++) cin>>node[i].num>>node[i].w;
	for(int i=1;i<=3;i++){
		if(n%node[i].num==0) minn=min(minn,n/node[i].num*node[i].w);
		else minn=min(minn,(n/node[i].num+1)*node[i].w);
	}
	cout<<minn<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y;
}node[10];
int main(){
	for(int i=1;i<=7;i++) cin>>node[i].x>>node[i].y;
	int maxx=0,pos;
	for(int i=1;i<=7;i++){
		if(node[i].x+node[i].y>maxx){
			pos=i;
			maxx=node[i].x+node[i].y;
		}
	}
	if(maxx<=8) cout<<0<<endl;
	else cout<<pos<<endl;
	return 0;
}

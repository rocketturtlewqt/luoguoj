#include<bits/stdc++.h>
using namespace std;
int n;const int MAXN=200000;
typedef long long ll;
struct Node{
	ll start,end;
}node[MAXN];
bool compare(struct Node a,struct Node b){
	if(a.start==b.start) return a.end<b.end;
	return a.start<b.start;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>node[i].start>>node[i].end;
	}
	sort(node+1,node+n+1,compare);
    ll sum=0,max_r=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
    	if(max_r<=node[i].end) sum+=node[i].end-max(node[i].start,max_r)+1,max_r=node[i].end+1;
    }
 	printf("%lld\n",sum);
	return 0;
}



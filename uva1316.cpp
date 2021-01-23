#include<algorithm>
#include<string.h>
#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5;
int n;
struct Node{
	int val,time;
}node[MAXN];
bool compare(struct Node a,struct Node b){
	return a.time<b.time;
}
int main(){
    while(cin>>n&&n){
    	for(int i=1;i<=n;i++) cin>>node[i].val>>node[i].time;
    	sort(node+1,node+n+1,compare);
    	int maxx=0,sum=0;
    	for(int i=1;i<=n;i++){
    		maxx=max(maxx,node[i].val);
    		if(node[i].time!=node[i+1].time) sum+=maxx,maxx=0;
		}
		cout<<sum<<endl;
	}
	return 0;
} 

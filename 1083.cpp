#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20000000];
struct Node{
	int num,start,end,mark;
}node[20000000];
inline void pushdown(int index){
	if(node[index].mark){
		node[index<<1].num-=node[index].mark;
		node[index<<1|1].num-=node[index].mark;
		node[index<<1].mark+=node[index].mark;
		node[index<<1|1].mark+=node[index].mark;
		node[index].mark=0;
	}
}
inline void build(int index,int start,int end){
	if(start==end){
		scanf("%d",&node[index].num);
		node[index].start=node[index].end=start;
	}
	else{
		int mid=(start+end)>>1;
		build(index<<1,start,mid);
		build(index<<1|1,mid+1,end);
		node[index].num=min(node[index<<1].num,node[index<<1|1].num);
		node[index].start=start;node[index].end=end;
	}
}
inline int update(int index,int start,int end,int num){
	if(node[index].start>end||node[index].end<start) return;
    if(node[index].start>=start&&node[index].end<=end){
    	node[index].num+=num;node[index].mark+=num;
    	return;
	}
    pushdown(index);
    update(index<<1,start,end);update(index<<1|1,start,end);
    node[index].num=min(node[index<<1].num,node[index<<1|1].num);
}
inline int query(int index,int start,int end,int num){
	if(node[index].start>end||node[index].end<start) return 0x3f3f3f3f;
	if(node[index].start>=start&&node[index].end<=end) return node[index].num;
	pushdown(index);
	return min(query(index<<1,start,end),query(index<<1|1,start,end));
}
int main(){
	cin>>n>>m;
	build(1,1,n);
    for(int i=1;i<=m;i++){
    	cin>>
	}
}

#include<bits/stdc++.h>
using namespace std;
struct Node{
	int pos,num;
}node[100005];
int n,q,a[100005];
bool compare(struct Node a,struct Node b){
	return a.num<b.num;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		node[i].num=x;node[i].pos=i;
	}
	sort(node+1,node+n+1,compare);
	for(int i=1;i<=n;i++) a[i]=node[i].num;
	cin>>q;
	for(int i=1;i<=q;i++){
		int num;cin>>num;
	    int pos=lower_bound(a+1,a+n+1,num)-a;
        if(pos==n+1||node[pos].num!=num||node[pos].pos==0) cout<<0<<endl;
        else cout<<node[pos].pos<<endl;
	}
	return 0;
}

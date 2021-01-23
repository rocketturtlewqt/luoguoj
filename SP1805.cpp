#include<algorithm>
#include<stack>
#include<string.h>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
struct Node{
	int h,w;
};
ll h[200000],ans=0;
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		if(n==0) return 0;
		for(int i=1;i<=n;i++) scanf("%d",&h[i]);
		stack<Node> q;
		h[n+1]=0;
		for(int i=1;i<=n+1;i++){
			ll width=0;
			while(!q.empty()&&h[i]<q.top().h){
				width+=q.top().w;
				ans=max(ans,width*q.top().h);
				q.pop();
			}
			q.push((Node){h[i],width+1});
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

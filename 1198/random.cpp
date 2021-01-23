#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int m;
ll D;
inline int random(ll num){
	return (ll)rand()*rand()%num;
}
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	m=random(20)+1;D=random(20000)+1;
	printf("%d %lld\n",m,D);
	while(m--){
		int r=random(2);
		char c;
		if(r==0){
			c='A';
			ll x=random(2000000);
			printf("%c %lld\n",c,x);
		}
		else{
			c=='Q';
			int x=random(7);
			printf("%c %d\n",c,x);
		}
	}
	puts("");
	return 0;
}

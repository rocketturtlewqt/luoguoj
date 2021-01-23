#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll c;
inline int random(int n){
	return (ll)rand()*rand()%n;
}
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	n=random(20)+1;
	c=random(2)+1;
	printf("%d %d\n",n,c);
	int x;
	for(int i=1;i<=n;i++) x=random(5),printf("%d ",x);
	puts("");
	return 0;
}


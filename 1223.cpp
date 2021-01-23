#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
	int num,pos;
}a[2000];
bool compare(struct Node b,struct Node c){
	if(b.num==c.num) return b.pos<c.pos;
	return b.num<c.num;
}
int main(){
	cin>>n;a[0].num=a[0].pos=0;
	for(int i=1;i<=n;i++) cin>>a[i].num,a[i].pos=i;;
	sort(a+1,a+n+1,compare);
	for(int i=1;i<=n;i++) printf("%d ",a[i].pos);
	puts("");
	double sum=0;
	for(int i=1;i<=n;i++) sum+=i*a[n-i].num;
	printf("%.2f\n",sum/n);
	return 0;
}

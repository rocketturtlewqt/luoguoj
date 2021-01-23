#include<bits/stdc++.h>
using namespace std;
struct Cow{
	int maxx,minn;
}cow[3000];
struct Power{
	int p,num;
}power[3000];
int n,m;
bool compare(struct Cow a,struct Cow b){
	return a.minn>b.minn;
}
bool cm(struct Power a,struct Power b){
	return a.p>b.p;
}
int main(){
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>cow[i].minn>>cow[i].maxx;
	for(int i=1;i<=m;i++) cin>>power[i].p>>power[i].num;
	sort(cow+1,cow+n+1,compare);
	sort(power+1,power+m+1,cm);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(power[j].p>=cow[i].minn&&power[j].p<=cow[i].maxx&&power[j].num){
				ans++;
				power[j].num--;
				break;
			}
		}
    }
	cout<<ans<<endl;
	return 0;
}

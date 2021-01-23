#include<bits/stdc++.h>
using namespace std;
const int maxium=50;
struct Lake{
	int f,d,t;
}lake[maxium];
int n,h,timee[50],a[50];
inline int find_max(int end){
	int pos,maxx=-1;
	for(int i=end;i>=1;i--)
    if(maxx<a[i]) pos=i,maxx=a[i];
    return pos;
}
int find(int j)//用来找当前最大的值
{
    int c=-1,bj;
    for(int i=j;i>=1;i--)
    if(c<a[i]) c=a[i],bj=i;//更新最大值
    return bj;
}
int main(){
	cin>>n>>h;h*=60;int ans=0;
	for(int i=1;i<=n;i++) cin>>lake[i].f;
	for(int i=1;i<=n;i++) cin>>lake[i].d;
	for(int i=1;i<=n-1;i++) cin>>lake[i].t;
	for(int i=1;i<=n;i++) timee[i]=timee[i-1]+5*lake[i-1].t;
	for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++) a[k]=lake[k].f;
		int j=i,sum_fish=0,sum_time=timee[i];
		while(j){
			int pos=find_max(j);
			if(a[pos]<=0) break;
            sum_fish+=a[pos];
			a[pos]-=lake[pos].d;
            sum_time+=5; 
            if(sum_time+5>h) break;
		}
		ans=max(ans,sum_fish);
	}
	cout<<ans<<endl;
	return 0;
}

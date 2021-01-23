#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll D,last_t,lg[200002],f[200002][21],a[200002];
int m,ans;
inline void change(int pos){
	f[pos][0]=a[pos];
	for(int i=1;pos-(1<<i)>=0;i++) f[pos][i]=max(f[pos][i-1],f[pos-(1<<(i-1))][i-1]);
}
inline void start(){
	lg[0]=-1;
	for(int i=1;i<=300000;i++) lg[i]=lg[i>>1]+1;
}
inline ll RMQ(int l,int r){
    double t=log(r-l+1)/log(2);
    int K=t;
    return max(f[r][K],f[l+(1<<K)-1][K]);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	cin>>m>>D;
	start();
	for(int i=1;i<=m;i++){
		char c;
	    cin>>c;
		if(c=='A'){
			ll x;
			cin>>x;
			a[++ans]=(x+last_t)%D;
			change(ans);
		}
		else{
			int x;cin>>x;
			if(x==1){
				cout<<a[ans]<<endl;
				last_t=a[ans];
			}
			else{
				last_t=RMQ(ans-x+1,ans);
				cout<<last_t<<endl;
			}
		}
	} 
	return 0;
}

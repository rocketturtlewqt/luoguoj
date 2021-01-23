#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll x,y;
}node[20000];
//ans[1]~ans[ans[0]]是从最低位到最高位（简而言之——倒序~） 
int n;
ll ans[4400],minx[4400],chen[4400]={1,1};
bool compare(struct Node a,struct Node b){
	return a.x*a.y<b.x*b.y;
}
void cheng(int k)//这里用的连乘，chen[]保存当前n个人乘的结果，每次除的时候就方便些 
{
    int t=0;
    for(int i=1;i<=chen[0];i++)
    {
        chen[i]=chen[i]*k+t;
        t=chen[i]/10;
        chen[i]%=10;
        if(t>0&&i>=chen[0])
        chen[0]++;
    }
}
void chu(int k)//除，调用chen[]，结果放到ans里 
{
    int t=0,ok=1;
    memset(ans,0,sizeof(ans));
    for(int i=chen[0];i>0;i--)
    {
        ans[i]=(chen[i]+10*t)/k;
        t=(chen[i]+10*t)%k;
        if(ans[i]&&ok)
        ans[0]=i,ok=0; 
    }       
}
void print(long long q[])
{
    int i;
    for(i=q[0];i>0&&q[i]==0;i--);
    for(;i>0;i--)
    cout<<q[i];
    cout<<endl;
}
bool cpr(long long q[],long long w[])//先比位数，最从高位到低位比，true就换，false就不换 
{
    if(q[0]>w[0])  return false;
    if(q[0]<w[0])  return true;
    for(int i=q[0];i>0;i--)
    {
        if(q[i]<w[i])  return true;
        if(q[i]>w[i])  return false;
    }
    return false;
}
int main(){
	cin>>n;
	cin>>node[0].x>>node[0].y;
	for(int i=1;i<=n;i++) cin>>node[i].x>>node[i].y;
	sort(node+1,node+n+1,compare);
	for(int i=0;i<n;i++){
		cheng(node[i].x);
		chu(node[i+1].y);
		if(cpr(minx,ans)) memcpy(minx,ans,sizeof(ans));
	}
	print(minx);
	return 0;
}

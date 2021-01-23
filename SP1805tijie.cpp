#include<cstdio>
#include<stack>
#include<cstring>
#include<iostream>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return f*x;
}//很伤心呢，看错范围了，最初没改成long long 类型的，爆了几次才发现QWQ
struct node{
    int h,w;
};//一个存高度，一个存宽度。
long long s[100100],ans=0;
int main(){//短的出乎我的意料。
    while(1){
        int n=read();
        if(n==0)return 0;
        for(int i=1;i<=n;i++){
            s[i]=read();
        }
        stack<node>st;
        s[n+1]=0;
        for(int i=1;i<=n+1;i++){
            long long W=0;
            while(!st.empty()&&s[i]<st.top().h){//单调栈！单调递增！
                W=W+st.top().w;
                ans=max(ans,W*st.top().h);
                st.pop();
            }
            st.push((node){s[i],W+1});
        }
        cout<<ans<<endl;
        ans=0;
    }
}

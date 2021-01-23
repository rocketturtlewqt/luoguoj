#include<bits/stdc++.h>
using namespace std;
int n,k,m,s,t,c[120],g[120][120],f[120][120],aa,bb,cc;
int main(){
    cin>>n>>k>>m>>s>>t;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    f[i][j]=0x3f3f3f3f;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=k;i++)
    for(int j=1;j<=k;j++)
    scanf("%d",&g[i][j]);
    for(int i=1;i<=m;i++){
        cin>>aa>>bb>>cc;
        if(!g[c[bb]][c[aa]]&&c[bb]!=c[aa])f[aa][bb]=min(f[aa][bb],cc);
        if(!g[c[aa]][c[bb]]&&c[bb]!=c[aa])f[bb][aa]=min(f[bb][aa],cc);
    }
    if(c[s]==c[t]) return puts("-1"),0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(i!=j)
        for(int k=1;k<=n;k++){
            if(j!=k&&i!=k){
                if(f[i][k]+f[k][j]<f[i][j])
                f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
    if(f[s][t]==0x3f3f3f3f) puts("-1");
    else printf("%d\n",f[s][t]);
}

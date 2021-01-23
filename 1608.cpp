#include <bits/stdc++.h>
using namespace std;

int e[2010][2010],n,cnt[2010],dis[2010];
bool book[2010];

void spfa(int s,int t){
    queue <int> sta;
    sta.push(s);
    book[s]=1;
    cnt[s]=1;
    dis[s]=0;
    while(!sta.empty()){
        int k=sta.front();
        sta.pop();
        book[k]=0;
        if(k==t)
            continue;
        for(register int i=1;i<=n;i=-~i){
            if(dis[i]==dis[k]+e[k][i])
                cnt[i]+=cnt[k];
            if(dis[i]>dis[k]+e[k][i]){
                dis[i]=dis[k]+e[k][i];
                cnt[i]=cnt[k];
            }
            if(cnt[i] && !book[i]){
                book[i]=1;
                sta.push(i);
            }
        }
        cnt[k]=0;
    }
}

int main(){
    int x,y,z,i,j,k,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i=-~i)
        for(j=1;j<=n;j=-~j)
            e[i][j]=1000000000;
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        e[x][y]=min(e[x][y],z);
    }
    for(i=1;i<=n;i=-~i)
        dis[i]=1000000000;
    spfa(1,n);
    printf("%d\n",cnt[1]);
    if(dis[n]==1000000000)
        printf("No answer");
    else
        printf("%d %d",dis[n],cnt[n]);
    return 0;
}

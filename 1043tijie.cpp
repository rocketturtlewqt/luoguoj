#include<bits/stdc++.h>
using namespace std;
int n,m,f1[110][110][110],f2[110][110][110],a[110],sum[110];
int mod(int x){
    return (x%10+10)%10;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];sum[i]=sum[i-1]+a[i];}
    for(int i=1;i<=n;i++){a[i+n]=a[i],sum[i+n]=sum[i]+sum[n];}
    memset(f2,127,sizeof(f2));//f2记录的是最小值 所以要初始化为极大值
    for(int i=1;i<=2*n;i++){
        for(int j=i;j<=2*n;j++){
            f1[i][j][1]=f2[i][j][1]=mod(sum[j]-sum[i-1]);//预处理每段的值
        }
    }
    for(int l=1;l<=n;l++){//区间长度
        for(int i=1,j=i+l-1;j<=2*n;i++,j++){//左右端点
            for(int h=2;h<=m;h++){//段数
                for(int k=i+h-1;k<j;k++){//短点
                    f1[i][j][h]=max(f1[i][j][h],f1[i][k][h-1]*mod(sum[j]-sum[k]));
                    f2[i][j][h]=min(f2[i][j][h],f2[i][k][h-1]*mod(sum[j]-sum[k]));
                }
            }
        }
    }
    int maxn=0,minn=0x7fffffff;
    for(int i=1;i<=n;i++){//找答案啦～～～
        maxn=max(maxn,f1[i][i+n-1][m]);
        minn=min(minn,f2[i][i+n-1][m]);
    }
    cout<<minn<<endl<<maxn;
}
